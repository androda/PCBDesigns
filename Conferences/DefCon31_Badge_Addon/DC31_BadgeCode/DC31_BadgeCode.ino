/*
 * Copyright Tech by Androda, LLC
 * July 2023
 * 
 */

#include <Adafruit_SHTC3.h>

// So many overrides
#include "hal_conf_custom.h"

#define SDA PB_11
#define SCL PB_10

Adafruit_SHTC3 sht = Adafruit_SHTC3();  // https://github.com/adafruit/Adafruit_SHTC3/blob/master/examples/SHTC3test/SHTC3test.ino

#define RED PA8
#define GREEN PA9
#define BLUE PA10

HardwareTimer timer1(TIM1);
uint32_t channelRed = STM_PIN_CHANNEL(pinmap_function(digitalPinToPinName(RED), PinMap_PWM));
uint32_t channelGreen = STM_PIN_CHANNEL(pinmap_function(digitalPinToPinName(GREEN), PinMap_PWM));
uint32_t channelBlue = STM_PIN_CHANNEL(pinmap_function(digitalPinToPinName(BLUE), PinMap_PWM));

#define HAL_I2C_MODULE_ENABLED

/*
 * PA8 is Red
 * PA9 is Green
 * PA10 is Blue
 * 
 * PB10 is SCL
 * PB11 is SDA
 * 
 * Serial output is PA2
 */

// Even more overrides
const PinMap PinMap_I2C_SDA[] = {
  {PB_7,  I2C1, STM_PIN_DATA(STM_MODE_AF_OD, GPIO_NOPULL, GPIO_AF1_I2C1)},
  {PB_9,  I2C1, STM_PIN_DATA(STM_MODE_AF_OD, GPIO_NOPULL, GPIO_AF1_I2C1)},
  {PB_11, I2C2, STM_PIN_DATA(STM_MODE_AF_OD, GPIO_PULLUP, GPIO_AF1_I2C2)},
  {PF_7,  I2C2, STM_PIN_DATA(STM_MODE_AF_OD, GPIO_NOPULL, GPIO_AF_NONE)},
  {NC,    NP,   0}
};
const PinMap PinMap_I2C_SCL[] = {
  {PB_6,  I2C1, STM_PIN_DATA(STM_MODE_AF_OD, GPIO_NOPULL, GPIO_AF1_I2C1)},
  {PB_8,  I2C1, STM_PIN_DATA(STM_MODE_AF_OD, GPIO_NOPULL, GPIO_AF1_I2C1)},
  {PB_10, I2C2, STM_PIN_DATA(STM_MODE_AF_OD, GPIO_PULLUP, GPIO_AF1_I2C2)},
  {PF_6,  I2C2, STM_PIN_DATA(STM_MODE_AF_OD, GPIO_NOPULL, GPIO_AF_NONE)},
  {NC,    NP,   0}
};


void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {};
  RCC_PeriphCLKInitTypeDef RCC_PeriphClkInit = {};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_OFF;
  RCC_OscInitStruct.PLL.PREDIV = RCC_PREDIV_DIV1;
  // Enable the LSI for use with RCC and wake interrupts
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSI;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
                                | RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK) {
    Error_Handler();
  }
}

void setup() {
  digitalWrite(SDA, 1);
  digitalWrite(SCL, 1);
  pinMode(SDA, OUTPUT);
  pinMode(SCL, OUTPUT);

  pinMode(RED, OUTPUT_OPEN_DRAIN);
  pinMode(GREEN, OUTPUT_OPEN_DRAIN);
  pinMode(BLUE, OUTPUT_OPEN_DRAIN);
  digitalWrite(RED, 1);
  digitalWrite(GREEN, 1);
  digitalWrite(BLUE, 1);

  Serial.begin(9600);

  Wire.setSDA(SDA);
  Wire.setSCL(SCL);
  Wire.begin();
  
  digitalWrite(RED, 1);
  digitalWrite(GREEN, 1);
  digitalWrite(BLUE, 1);
  Serial.println("");
  Serial.println("-----------------");
  if (sht.begin()) {
    // Flash green twice
    Serial.println("SHT Init Good");
    digitalWrite(RED, 1);
    digitalWrite(GREEN, 1);
    digitalWrite(BLUE, 1);
    digitalWrite(GREEN, 0);
    delay(5);
    digitalWrite(GREEN, 1);
  } else {
    // Flash red every second
    Serial.println("SHT Init Fail");
    digitalWrite(RED, 1);
    digitalWrite(GREEN, 1);
    digitalWrite(BLUE, 1);
    while(true) {
      digitalWrite(RED, 1);
      delay(2000);
      digitalWrite(RED, 0);
      delay(15);
      if (sht.begin()) {
        Serial.println("SHT Init Retry Good");
        break;
      }
      Serial.println("SHT Init Retry Fail");
    }
  }

  pwmRun();
  pwmStop();

  //// Set up one-second interrupts
  TIM_TypeDef *Instance = TIM6;
  HardwareTimer *MyTim = new HardwareTimer(Instance);
  MyTim->setMode(2, TIMER_OUTPUT_COMPARE);
  MyTim->setOverflow(1, HERTZ_FORMAT);
  MyTim->attachInterrupt(hardwareTimerWake);
  MyTim->resume();

  // Sleep
  HAL_PWR_EnterSLEEPMode(42, PWR_SLEEPENTRY_WFI);
}

void hardwareTimerWake() {
  sensors_event_t humidity, temp;
  sht.sleep(true);
  delay(10);
  sht.sleep(false);
  if (sht.getEvent(&humidity, &temp)) {
    double heatIndex = calculateHeatIndex(humidity, temp);
    showHeatIndexOnLed(heatIndex);
  } else {
    pwmRun();
    pwmRed();
    delay(10);
    pwmStop();
  }
  // Sleep
  HAL_PWR_EnterSLEEPMode(42, PWR_SLEEPENTRY_WFI);
}

void showHeatIndexOnLed(double heatIndex) {
  /*
   * Category barriers:
   * < 80 after HI conversion, not in the caution zone at all
   * 80 to 90 is Caution
   * > 90 and < 104 is Extreme Caution
   * 104 to 125 is Danger
   * > 125 is Extreme Danger
   */
   if (heatIndex < 80) {
    pwmBits(0x100, 10, 100, 10);  // Blue
    pwmStop();
   } else if (heatIndex < 90) {
    pwmBits(0x10, 10, 100, 25);  // Green
    pwmStop();
   } else if (heatIndex < 104) {
    pwmBits(0x11, 10, 100, 500);  // Yellow
    pwmStop();
   } else if (heatIndex < 125) {
    pwmBits(0x1, 10, 20, 700);  // Red
    pwmStop();
   } else {
    pwmBits(0x101, 10, 20, 1000);  // Purple
    pwmStop();
   }
}

void pwmBits(uint32_t bitsToPwm, uint32_t onDuration, uint32_t offDuration, uint32_t loops) {
  for (; loops > 0; loops--) {
    // ON
    WRITE_REG(TIM1->CCER, bitsToPwm);
    for (uint32_t spacer = onDuration;spacer > 0; spacer--) {
      asm("nop");
    }
    // OFF
    CLEAR_BIT(TIM1->CCER, 0xFFFFFFFF);
    for (uint32_t spacer = offDuration;spacer > 0; spacer--) {
      asm("nop");
    }
  }
}

double calculateHeatIndex(sensors_event_t humidity, sensors_event_t temp) {
  double degrees_f = (temp.temperature * 1.8) + 32;
  double rh = humidity.relative_humidity;
  double result;
  
  float simpleHeatIndex = 0.5D * (degrees_f + 61.0D + ((degrees_f - 68.0D) * 1.2D) + (rh * 0.094D));
  Serial.print("SHI: ");Serial.println(simpleHeatIndex);

  if (((simpleHeatIndex + degrees_f) / 2.0D) > 80) {
    float seg1 = -42.379F + (2.04901523F * degrees_f);
    float seg2 = (10.14333127F * rh);
    float seg3 = (0.22475541F * degrees_f * rh);
    float seg4 = (0.00683783D * degrees_f * degrees_f);
    float seg5 = (0.05481717D * rh * rh);
    float seg6 = (0.00122874D * degrees_f * degrees_f * rh);
    float seg7 = (0.00085282D * degrees_f * rh * rh);
    float seg8 = (0.00000199D * degrees_f * degrees_f * rh * rh);
    double heatIndex = double(seg1) + double(seg2) - double(seg3) - double(seg4) - double(seg5) + double(seg6) + double(seg7) - double(seg8);

    //  Adjustments
    if (rh < 13 && degrees_f > 80 && degrees_f < 112) {
      double adjustment = ((13 - rh) / 4) * sqrt((17 - abs(degrees_f - 95.0)) / 17);
      heatIndex = heatIndex - adjustment;
    }
  
    if (rh > 85 && degrees_f > 80 && degrees_f < 87) {
      double adjustment = (((rh - 85) / 10) * ((87 - degrees_f) / 5));
      heatIndex = heatIndex - adjustment;
    }
    result = heatIndex;
  }
  
  return result;
}

void pwmRun() {
  timer1.pause();
  timer1.setPWM(channelRed, RED, 500053, 500000);
  timer1.setPWM(channelGreen, GREEN, 799, 10);
  timer1.setPWM(channelBlue, BLUE, 599, 10);
}

void pwmRed() {
  // CCER bit 0 should be 1
  // All other CCER bits are 0
  WRITE_REG(TIM1->CCER, 0x1);
}

void pwmStop() {
  CLEAR_BIT(TIM1->CCER, 0xFFFFFFFF);
}

void loop() {
}

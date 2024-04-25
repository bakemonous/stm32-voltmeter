/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
/*#include "tm1637.h"*/
#include "delay_micros.h"
#include "tm1637.h"
#include "stdio.h"
#include "math.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc1;

UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */
int adcResult = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_ADC1_Init(void);
static void MX_USART1_UART_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_ADC1_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
  DWT_Init();        // инициализация DWT
   set_brightness(7); // 0 - 7 яркость
   clearDisplay();    // очистка дисплея

   int8_t TimeDisp[4] = {0,};
   int n=0;
   int k;
   int k1;
   int k2;
   int k3;
   int k4;
   int k5;
   int k6;
   int k7;
   int k8;
   int k9;
   int i;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	   uint8_t str1[]="yy";
	   uint8_t str[]="yy";
		HAL_Delay(100);
		HAL_ADC_Start(&hadc1);
		while (i<8){
		 	adcResult = HAL_ADC_GetValue(&hadc1);
		 	k=(((adcResult*980)/1241)*30)/10;
		    k=(((adcResult*980)/1241)*30)/10;
			sprintf((char *)str1,"%d\n", k);
			HAL_UART_Transmit(&huart1,str1,sizeof(str1)+2,15);
		    k1=k1+k;
			i=i+1;
		}
		i=0;
		n=k1/8;
		k1=0;
		/*		HAL_Delay(10);
		 	adcResult = HAL_ADC_GetValue(&hadc1);
		 	n=(((adcResult*980)/1241)*30)/10;
			HAL_Delay(100);
			HAL_ADC_Stop(&hadc1);
			HAL_ADC_Start(&hadc1);*/
	/*    k=(((adcResult*980)/1241)*30)/10;
		HAL_Delay(100);
		HAL_ADC_Stop(&hadc1);
		HAL_ADC_Start(&hadc1);
		adcResult = HAL_ADC_GetValue(&hadc1);
		HAL_Delay(10);
        k1=(((adcResult*980)/1241)*30)/10;
		HAL_Delay(10);
		HAL_ADC_Stop(&hadc1);
		HAL_ADC_Start(&hadc1);
 		adcResult = HAL_ADC_GetValue(&hadc1);
		HAL_Delay(10);
        k2=(((adcResult*980)/1241)*30)/10;
		HAL_Delay(10);
		HAL_ADC_Stop(&hadc1);
		HAL_ADC_Start(&hadc1);
  		adcResult = HAL_ADC_GetValue(&hadc1);
		HAL_Delay(100);
        k3=(((adcResult*980)/1241)*30)/10;
		HAL_Delay(100);
		HAL_ADC_Stop(&hadc1);
		HAL_ADC_Start(&hadc1);
   		adcResult = HAL_ADC_GetValue(&hadc1);
		HAL_Delay(10);
        k4=(((adcResult*980)/1241)*30)/10;
		HAL_Delay(10);
		HAL_ADC_Stop(&hadc1);
		HAL_ADC_Start(&hadc1);
        adcResult = HAL_ADC_GetValue(&hadc1);
		HAL_ADC_PollForConversion(&hadc1, 100);
		HAL_Delay(10);
        k5=(((adcResult*980)/1241)*30)/10;
		HAL_Delay(10);
		HAL_ADC_Stop(&hadc1);
		HAL_ADC_Start(&hadc1);
     	adcResult = HAL_ADC_GetValue(&hadc1);
		HAL_Delay(100);
        k6=(((adcResult*980)/1241)*30)/10;
		HAL_Delay(100);
		HAL_ADC_Stop(&hadc1);
		HAL_ADC_Start(&hadc1);
      	adcResult = HAL_ADC_GetValue(&hadc1);
		HAL_Delay(10);
        k7=(((adcResult*980)/1241)*30)/10;
		HAL_Delay(10);
		HAL_ADC_Stop(&hadc1);
		HAL_ADC_Start(&hadc1);
       	adcResult = HAL_ADC_GetValue(&hadc1);
		HAL_Delay(10);
        k8=(((adcResult*980)/1241)*30)/10;
		HAL_Delay(10);
		HAL_ADC_Stop(&hadc1);
		HAL_ADC_Start(&hadc1);
        adcResult = HAL_ADC_GetValue(&hadc1);
		HAL_Delay(10);
        k9=(((adcResult*980)/1241)*30)/10;
		HAL_ADC_Stop(&hadc1);
        if ((k<k1)&&(k<k2)&&(k<k3)&&(k<k4)&&(k<k5)&&(k<k6)&&(k<k7)&&(k<k8)&&(k<k9)){
        	n=k;
        }
        else if (( k1<k2 ) && ( k1<k3 ) && ( k1<k4 )&&( k1<k5 )&&( k1<k6 )&&( k1<k7 )&&(k1<k8)&&(k1<k9)){
        	n=k1;
        }
        else if ((k2<k3)&&(k2<k4)&&(k2<k5)&&(k2<k6)&&(k2<k7)&&(k2<k8)&&(k2<k9)){
        	n=k2;
        }
        else if ((k3<k4)&&(k3<k5)&&(k3<k6)&&(k3<k7)&&(k3<k8)&&(k3<k9)){
        	n=k3;
        }
        else if ((k4<k5)&&(k4<k6)&&(k4<k7)&&(k4<k8)&&(k4<k9)){
        	n=k4;
        }
        else if ((k5<k6)&&(k5<k7)&&(k5<k8)&&(k5<k9)){
        	n=k5;
        }
        else if ((k6<k7)&&(k6<k8)&&(k6<k9)){
        	n=k6;
        }
        else if ((k7<k8)&&(k7<k9)){
        	n=k7;
        }
        else if ((k8<k9)){
        	n=k8;
        }
        else {
        	n=k9;
        }*/
	    int n1=0;
	    int n2=0;
	    int n3=0;

		sprintf((char *)str,"%d\n", n);
		//HAL_UART_Transmit(&huart1,str,sizeof(str)+2,15);
		HAL_Delay(100);

		          //point(1); // двоеточие, 0 - мигает, 1 - горит постоянно, удалить функцию - нет двоеточия
       	TimeDisp[0] = 0;
       	TimeDisp[1] = 0;
       	TimeDisp[2] = 0;
       	TimeDisp[3] = 0;

		   if (n>1000){
        	TimeDisp[0] = floor(n/1000);
        }
        if (n>100){
        	if (n>1000){
        	   n1=(floor(n/1000))*1000;
               TimeDisp[1] = floor((n-n1)/100);
        	}
        	else{
        		TimeDisp[1] = floor(n/100);
        	}
        }
        if (n>10){
        	if (n>1000){
        	n1=(floor(n/1000))*1000;
        	}
        	if (n>100){
        		if (n-n1==0){
        			n2=0;
                	TimeDisp[2] = n2;
        		}
        		else{
            	n2=(floor((n-n1)/100))*100;
            	TimeDisp[2] = floor((n-n1-n2)/10);
        		}
        	}
            else{TimeDisp[2] = floor(n/10);//(dot-0x80);
            }

        }
        if (n>1){
        	if (n>1000){
        	n1=(floor(n/1000))*1000;
        	}
        	if (n>100){
        		if (n-n1==0){
        			n2=0;
        	    }
        		else{
            	n2=(floor((n-n1)/100))*100;
        		}
        	}
        	if (n>10){
        		if (n-n1-n2==0){
        			n3=0;
        			TimeDisp[3] =n-n1-n2-n3;
        		}
        		else{
            	n3=(floor((n-n1-n2)/10))*10;
            	TimeDisp[3] =n-n1-n2-n3;
        		}
        	}

    		if (n-n1-n2-n3==0){
            	TimeDisp[3] = 0;
    		}
    		if(n<10){
    			TimeDisp[3] = n;
    		}


        }

		display_mass(TimeDisp);

		HAL_Delay(100);

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 25;
  RCC_OscInitStruct.PLL.PLLN = 144;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */

  /** Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion)
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV2;
  hadc1.Init.Resolution = ADC_RESOLUTION_12B;
  hadc1.Init.ScanConvMode = ENABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 2;
  hadc1.Init.DMAContinuousRequests = DISABLE;
  hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
  */
  sConfig.Channel = ADC_CHANNEL_0;
  sConfig.Rank = 1;
  sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
  */
  sConfig.Rank = 2;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, CLK_Pin|DIO_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : CLK_Pin DIO_Pin */
  GPIO_InitStruct.Pin = CLK_Pin|DIO_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

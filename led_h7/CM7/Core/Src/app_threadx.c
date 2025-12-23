/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    app_threadx.c
  * @author  MCD Application Team
  * @brief   ThreadX applicative file
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2020-2021 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/* Includes ------------------------------------------------------------------*/
#include "app_threadx.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "main.h"
#include "app_netxduo.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define THREAD_STACK_SIZE 1024
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */
UART_HandleTypeDef huart2;

uint8_t thread_stack1[THREAD_STACK_SIZE];
TX_THREAD thread_ptr1;

uint8_t thread_stack2[THREAD_STACK_SIZE];
TX_THREAD thread_ptr2;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */
void MX_GPIO_Init(void);
VOID LD1_thread_entry(ULONG initial_input);
VOID LD2_thread_entry(ULONG initial_input);
int _write(int file, char *ptr, int len)
{
	int DataIdx;

	for(DataIdx = 0; DataIdx < len; DataIdx++)
	{
		HAL_UART_Transmit(&huart2, (uint8_t *)ptr++, 1, 100);
	}
	return len;
}
/* USER CODE END PFP */

/**
  * @brief  Application ThreadX Initialization.
  * @param memory_ptr: memory pointer
  * @retval int
  */
UINT App_ThreadX_Init(VOID *memory_ptr)
{
  UINT ret = TX_SUCCESS;
  /* USER CODE BEGIN App_ThreadX_MEM_POOL */

  /* USER CODE END App_ThreadX_MEM_POOL */

  /* USER CODE BEGIN App_ThreadX_Init */
  tx_thread_create(&thread_ptr1,"LD1_thread",LD1_thread_entry,0x1234,thread_stack1,THREAD_STACK_SIZE,15,15,1,TX_AUTO_START);
  tx_thread_create(&thread_ptr2,"LD2_thread",LD2_thread_entry,0x1234,thread_stack2,THREAD_STACK_SIZE,15,15,1,TX_AUTO_START);
  /* USER CODE END App_ThreadX_Init */

  return ret;
}

  /**
  * @brief  Function that implements the kernel's initialization.
  * @param  None
  * @retval None
  */
void MX_ThreadX_Init(void)
{
  /* USER CODE BEGIN  Before_Kernel_Start */
  MX_GPIO_Init();          // ✅ Must happen before scheduler
  /* USER CODE END  Before_Kernel_Start */

  tx_kernel_enter();

  /* USER CODE BEGIN  Kernel_Start_Error */

  /* USER CODE END  Kernel_Start_Error */
}

/* USER CODE BEGIN 2 */
VOID LD1_thread_entry (ULONG initial_input){
	while(1){
		HAL_GPIO_TogglePin(GPIOI, GPIO_PIN_13);
		printf("This is thread 1\r\n");
		tx_thread_sleep(100);
	}
}

VOID LD2_thread_entry (ULONG initial_input){
	while(1){
		HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_3);
		printf("This is thread 2\r\n");
		tx_thread_sleep(200);
	}
}

void MX_GPIO_Init(void)
{
  // Enable GPIO port clocks
  __HAL_RCC_GPIOI_CLK_ENABLE();  // LD6
  __HAL_RCC_GPIOD_CLK_ENABLE();  // LD8

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  // Configure LD6 (PI13)
  GPIO_InitStruct.Pin = GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOI, &GPIO_InitStruct);

  // Configure LD8 (PD3)
  GPIO_InitStruct.Pin = GPIO_PIN_3;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);
}
/* USER CODE END 2 */

#include "MeMCore.h"
/**
 * \par Copyright (C), 2012-2016, MakeBlock
 * \class   MeGyro
 * \brief   Driver for MeColorSensor module.
 * @file    MeColorSensor.h
 * @author  MakeBlock
 * @version V1.0.0
 * @date    2017/01/17
 * @brief   Header for MeColorSensor.cpp module.
 * \par Description
 * This file is a drive for MeColorSensor module, It supports MeColorSensor V1.0 device provided
 * by MakeBlock.
 * \par History:
 * <pre>
 * `<Author>`         `<Time>`        `<Version>`        `<Descr>`
 *  zzipeng         2017/04/12          1.0.0         complete the driver code.
 * </pre>
 *                 Attention please!
 *                 8mm~24mm detection distance.
 *              Mcore board only support PORT 1 2 3 4,as for this module!!
 */
//本例程示例单个颜色传感器模块工作，获取颜色识别值。单个模块工作数据返回率每秒6次。

MeColorSensor colorsensor(PORT_1);

uint8_t colorresult;
uint16_t redvalue=0,greenvalue=0,bluevalue=0,clearvalue=0;
uint8_t grayscale = 0;
long systime = 0,colorcode=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  colorsensor.SensorInit();
  systime = millis();
}

void loop() {
  // put your main code here, to run repeatedly:
while(1)
{
    colorresult = colorsensor.Returnresult();
    redvalue   = colorsensor.ReturnRedData();
    greenvalue = colorsensor.ReturnGreenData();
    bluevalue  = colorsensor.ReturnBlueData();
    clearvalue = colorsensor.ReturnClearData();
    colorcode = colorsensor.ReturnColorCode();//RGB24code
    grayscale  = colorsensor.ReturnGrayscale();

    Serial.print("R:");
    Serial.print(redvalue);
    Serial.print("\t");
    Serial.print("G:");
    Serial.print(greenvalue);
    Serial.print("\t");
    Serial.print("B:");
    Serial.print(bluevalue);
    Serial.print("\t");
    Serial.print("C:");
    Serial.print(clearvalue);
    Serial.print("\t");
    Serial.print("color:");
    switch(colorresult)
    {
      case BLACK:
      Serial.print("BLACK");
      break;
      case BLUE:
      Serial.print("BLUE");
      break;
      case PURPLE:
      Serial.print("PURPLE");
      break;
      case CYAN:
      Serial.print("CYAN");
      break;
      case YELLOW:
      Serial.print("YELLOW");
      break;
      case ORANGE:
      Serial.print("ORANGE");
      break;
      case GOLD:
      Serial.print("GOLD");
      break;
      case GREEN:
      Serial.print("GREEN");
      break;
      case RED:
      Serial.print("RED");
      break;
      case PINKE:
      Serial.print("PINKE");
      break;
      case WHITE:
      Serial.print("WHITE");
      break;
      default:
      break;    
     }
    Serial.print("\t");
    Serial.print("code:");
    Serial.print(colorcode,HEX);
    Serial.print("\t");
    Serial.print("grayscale:");
    Serial.println(grayscale);
  }
}

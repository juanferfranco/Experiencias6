/*
 * Copyright (c) 2015 RF Digital Corp. All Rights Reserved.
 *
 * The source code contained in this file and all intellectual property embodied in
 * or covering the source code is the property of RF Digital Corp. or its licensors.
 * Your right to use this source code and intellectual property is non-transferable,
 * non-sub licensable, revocable, and subject to terms and conditions of the
 * SIMBLEE SOFTWARE LICENSE AGREEMENT.
 * http://www.simblee.com/licenses/SimbleeSoftwareLicenseAgreement.txt
 *
 * THE SOURCE CODE IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND.
 *
 * This heading must NOT be removed from this file.
 */

#include "SimbleeCOM.h"
#define BUFFERSIZE 15

char payload[BUFFERSIZE] = {0};


void waitForSerialData();

void setup() {
  SimbleeCOM.begin();
  Serial.begin(9600);
  Serial.setTimeout(10000); // Timeout to 10000
}

void loop() {
  waitForSerialData();
}


void waitForSerialData(){
  unsigned char dataCounter = 0;
  int data;

  for(;;){
    if(Serial.available() > 0){
      data = Serial.read();
      payload[dataCounter] = data;
      dataCounter++;
      if(dataCounter == BUFFERSIZE) dataCounter = 0;
      if(data == '\n'){
        SimbleeCOM.send(payload, dataCounter);  
        break;
      }
    }
  }
}


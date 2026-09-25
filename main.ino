void setup(){
    initPins(); 
}

void loop(){
if(imuReady){
    readImu();
}
if(baroReady){
    readBaro();
}
}
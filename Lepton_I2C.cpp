#include <stdio.h>
#include "Lepton_I2C.h"
#include "leptonSDKEmb32PUB/LEPTON_SDK.h"
#include "leptonSDKEmb32PUB/LEPTON_SYS.h"
#include "leptonSDKEmb32PUB/LEPTON_Types.h"
#include "leptonSDKEmb32PUB/LEPTON_AGC.h"
bool _connected;

LEP_CAMERA_PORT_DESC_T _port;
LEP_SYS_FPA_TEMPERATURE_KELVIN_T fpa_temp_kelvin;
LEP_RESULT result;

int lepton_connect() {
	LEP_OpenPort(1, LEP_CCI_TWI, 400, &_port);
	_connected = true;
	return 0;
}

int lepton_temperature(){
	if(!_connected)
		lepton_connect();
	result = ((LEP_GetSysFpaTemperatureKelvin(&_port, &fpa_temp_kelvin)));
	printf("FPA temp kelvin: %i, code %i\n", fpa_temp_kelvin, result);
	return (fpa_temp_kelvin/100);
}


float raw2Celsius(float raw){
	float ambientTemperature = 25.0;
	float slope = 0.0217;
	return slope*raw+ambientTemperature-177.77;
}

void lepton_perform_ffc() {
	if(!_connected) {
		lepton_connect();
	}
	LEP_RunSysFFCNormalization(&_port);
}

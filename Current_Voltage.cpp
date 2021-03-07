#include <bits/stdc++.h>

using namespace std;

tuple <float,float,float>  voltage_drop_per_resistor(float r1, float r2, float r3, float tot_current){
	float v1, v2, v3;
	v1 = tot_current*r1;
	v2 = tot_current*r2;
	v3 = tot_current*r3;

	return make_tuple(v1, v2, v3);
}

tuple <float,float,float>  power_diss_per_resistor(float r1, float r2, float r3, float tot_current){
	float p1, p2, p3;

	p1 = (tot_current*tot_current)*r1;
	p2 = (tot_current*tot_current)*r2;
	p3 = (tot_current*tot_current)*r3;

	return make_tuple(p1, p2, p3);
}

tuple <float,float,float>  current_across_per_resistor(float r1, float r2, float r3, float volt){
	float i1, i2, i3;

	i1 = (volt/r1);
	i2 = (volt/r2);
	i3 = (volt/r3);

	return  make_tuple(i1, i2, i3);
}
void display1(float tot_current, float v1, float v2 , float v3, float p1, float p2, float p3 ){

	cout << "\nThe total current: " << tot_current << " A";
	cout << "\nVoltage drop in r1: " << v1 << " V";
	cout << "\nVoltage drop in r2: " << v2 << " V";
	cout << "\nVoltage drop in r3: " << v3 << " V";
	cout << "\nPower dissipated in r1: " << p1 << " W";
	cout << "\nPower dissipated in r2: " << p2 << " W";
	cout << "\nPower dissipated in r3: " << p3 << " W";
	cout << "\n";
}

void display2(float tot_resistance, float v1, float v2 , float v3, float i1, float i2, float i3, float p1, float p2, float p3 ){

	cout << "\nThe total resistance: " << tot_resistance << " Ohms";
	cout << "\nVoltage drop in r1: " << v1 << " V";
	cout << "\nVoltage drop in r2: " << v2 << " V";
	cout << "\nVoltage drop in r3: " << v3 << " V";
	cout << "\nCurrent across in r1: " << i1 << " A";
	cout << "\nCurrent across in r2: " << i2 << " A";
	cout << "\nCurrent across in r3: " << i3 << " A";
	cout << "\nPower dissipated in r1: " << p1 << " W";
	cout << "\nPower dissipated in r2: " << p2 << " W";
	cout << "\nPower dissipated in r3: " << p3 << " W";
	cout << "\n";
}





int main(){
	int ch, t;
	float tc, r1, r2, r3, v1, v2 ,v3, i1, i2 , i3, p1, p2, p3, volt, cap, tot_current, tot_resistance;
	while(1){
		cout << "\n1. Three resistor voltage divider circuit\n";
		cout << "2. Three resistor current divider circuit\n";
		cout << "3. RC Circuit\n";
		cout << "4. Exit\n";
		cout << "Enter you choice: ";
		cin >> ch;
		switch(ch){
			case 1:
				cout << "Enter the value of three resistors: ";
				while(1){
                    cin >> r1 >> r2 >> r3;
                    if(r1>0 && r2>0 && r3>0)
                        break;
                    else{
                        cout << "\nNot a valid resistor values!!\n";
                        cout << "Enter the value of three resistors again: ";
                    }
				}
				cout << "Enter the supply voltage: ";
				while(1){
                    cin >> volt;
                    if (volt > 0)
                        break;
                    else{
                        cout << "\nNot a valid voltage value!!\n";
                        cout << "Enter the supply voltage again: ";
                    }
				}
				tot_resistance = r1+r2+r3;
				tot_current = volt/tot_resistance;
				tie(v1, v2, v3) = voltage_drop_per_resistor(r1, r2, r3, tot_current);
				tie(p1, p2 , p3) = power_diss_per_resistor(r1, r2, r3, tot_current);
				display1(tot_current, v1, v2 , v3, p1, p2, p3 );
				break;

			case 2:
				cout << "Enter the value of three resistors: ";
				while(1){
                    cin >> r1 >> r2 >> r3;
                    if(r1>0 && r2>0 && r3>0)
                        break;
                    else{
                        cout << "\nNot a valid resistor values!!\n";
                        cout << "Enter the value of three resistors again: ";
                    }
				}
				cout << "Enter the supply current: ";
				while(1){
                    cin >> tot_current;
                    if (tot_current > 0)
                        break;
                    else{
                        cout << "\nNot a valid current value!!\n";
                        cout << "Enter the supply current again: ";
                    }
				}
				tot_resistance = 1/((1/r1)+(1/r2)+(1/r3));
				volt = tot_current*tot_resistance;
				tie(v1, v2, v3) = voltage_drop_per_resistor(r1, r2, r3, tot_current);
				tie(i1, i2, i3) = current_across_per_resistor(r1, r2, r3, volt);
				tie(p1, p2, p3) = power_diss_per_resistor(r1, r2, r3, tot_current);
				display2(tot_resistance, v1, v2 , v3 , i1, i2, i3, p1, p2, p3 );
				break;
			case 3:
                cout << "Enter the value of capacitor(in farads) :";
                cin >> cap;
                cout << "Enter the value of resistor(in ohms) :";
                cin >> tot_resistance;
                cout << "Enter the supply voltage :";
                cin >> volt;
                cout << "Enter time :";
                cin >> t;
                tc = tot_resistance*cap;
                cout << "The time constant :" <<tc << " secs" ;
                break;
			case 4:
				return 0;
            default:
                cout << "\nEnter valid choice!!\n";
		}
	}
}

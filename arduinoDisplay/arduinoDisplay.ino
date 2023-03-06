
#include <LiquidCrystal.h>

//to be replaced
byte running = 0;




namespace display {
    unsigned long int time = 0;






    unsigned int state = 0, insert = 0;


    byte prevBut = 0, prevCmd = 0;
    #define s1 6
    #define s2 7
    #define s3 8
    #define s4 9
    #define s5 10
    #define s6 13
    #define s7 A1
    #define s8 A2


    const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
    LiquidCrystal lcd(rs, en, d4, d5, d6, d7);




    byte arL[] = {
      B00001,
      B00011,
      B00111,
      B01111,
      B00111,
      B00011,
      B00001,
      B00000

    };
    byte arR[] = {
      B10000,
      B11000,
      B11100,
      B11110,
      B11100,
      B11000,
      B10000,
      B00000
    };
    byte sp[]{
      B01110,
      B01110,
      B01110,
      B11111,
      B11111,
      B01110,
      B00100,
      B00000
    };

    byte sd[]{
      B00000,
      B01010,
      B00000,
      B00000,
      B00000,
      B10001,
      B01110,
      B00000
    };




    void init() {
        lcd.begin(16, 2);

        pinMode(s1, INPUT);
        pinMode(s2, INPUT);
        pinMode(s3, INPUT);
        pinMode(s4, INPUT);
        pinMode(s5, INPUT);
        pinMode(s6, INPUT);
        pinMode(s7, INPUT);
        pinMode(s8, INPUT);

        lcd.createChar(1, arL);
        lcd.createChar(2, arR);
        lcd.createChar(3, sp);
        lcd.createChar(4, sd);
    }

    void welcome() {
        lcd.setCursor(0, 0);
        lcd.print("Hello Boss!     ");
        lcd.setCursor(0, 1);
        lcd.print("  Kya socha hai?      ");
    }

    namespace commonScreen {
        void loading() {
            if (time + 3000 < millis()) {
                lcd.setCursor(0, 0);
                lcd.print("**     1      ++");
                lcd.setCursor(0, 1);
                lcd.print("----------------");
            }
            else if (time + 2000 < millis()) {
                lcd.setCursor(0, 0);
                lcd.print("++     2      **");
                lcd.setCursor(0, 1);
                lcd.print("-------->>>>>>>>");
            }

            else if (time + 1000 < millis()) {
                lcd.setCursor(0, 0);
                lcd.print("**     3      ++");
                lcd.setCursor(0, 1);
                lcd.print("---->>>>>>>>>>>>");
            }
        }
        void gadiNikal() {
            lcd.setCursor(0, 0);
            lcd.print(" Chal-chal-chal ");
            lcd.setCursor(0, 1);
            lcd.print("   Gadi Nikal....");
        }
    }

    namespace mainOption {


        void start() {
            lcd.setCursor(0, 0);
            lcd.write(1);
            lcd.setCursor(1, 0);
            lcd.print("    START     ");
            lcd.setCursor(15, 0);
            lcd.write(2);
            lcd.setCursor(0, 1);
            lcd.print("BACK          OK");
        }

        void calib() {
            lcd.setCursor(0, 0);
            lcd.write(1);
            lcd.setCursor(15, 0);
            lcd.write(2);
            lcd.setCursor(1, 0);
            lcd.print("   CALIBRATE  ");
            lcd.setCursor(0, 1);
            lcd.print("BACK          OK");
        }


        void setting() {
            lcd.setCursor(0, 0);
            lcd.write(1);
            lcd.setCursor(15, 0);
            lcd.write(2);
            lcd.setCursor(0, 1);
            lcd.print("BACK          OK");
            lcd.setCursor(1, 0);
            lcd.print("    SETTING   ");
        }

    }

    namespace startOption {
        void runData() {
            lcd.setCursor(0, 0);
            lcd.print("TIME");
            lcd.setCursor(4, 0);
            lcd.print("-.-");
            lcd.setCursor(8, 0);
            lcd.print("SPEED");
            lcd.setCursor(13, 0);
            lcd.print("-.-");
            lcd.setCursor(0, 1);
            lcd.print("MAT");
            lcd.setCursor(3, 1);
            lcd.print("-.-.");
            lcd.setCursor(10, 1);
            lcd.print("LIGHT");
            lcd.setCursor(15, 1);
            lcd.print(".");
        }

        void finalData() {
            lcd.setCursor(0, 0);
            lcd.write(1);
            lcd.setCursor(1, 0);
            lcd.print("TIME");
            lcd.setCursor(15, 0);
            lcd.write(2);
            lcd.setCursor(0, 1);
            lcd.print("AVG.SPEED");
            lcd.setCursor(5, 0);
            lcd.print("-.-");
            lcd.setCursor(8, 0);
            lcd.print("       ");
            lcd.setCursor(10, 1);
            lcd.print("-.-");
            lcd.setCursor(13, 1);
            lcd.print("   ");
        }

        void trace() {
            lcd.setCursor(0, 0);
            lcd.write(1);
            lcd.setCursor(15, 0);
            lcd.write(2);
            lcd.setCursor(1, 0);
            lcd.print("    TRACE     ");
            lcd.setCursor(0, 1);
            lcd.print("BACK     FORWARD");
        }
    }

    namespace calibOption {
        void curData() {
            lcd.setCursor(0, 0);
            lcd.write(1);
            lcd.setCursor(15, 0);
            lcd.write(2);
            lcd.setCursor(0, 1);
            lcd.print("BACK          OK");
            lcd.setCursor(1, 0);
            lcd.print("  CURR. DATA  ");
        }

        void newData() {
            lcd.setCursor(0, 0);
            lcd.write(1);
            lcd.setCursor(15, 0);
            lcd.write(2);
            lcd.setCursor(0, 1);
            lcd.print("BACK          OK");
            lcd.setCursor(1, 0);
            lcd.print("   NEW DATA   ");
        }

        namespace calibData {
            void mini() {
                lcd.setCursor(0, 0);
                lcd.write(1);
                lcd.setCursor(15, 0);
                lcd.write(2);
                lcd.setCursor(0, 1);
                lcd.setCursor(1, 0);
                lcd.print("     MIN      ");
                lcd.print("      -.-       ");
            }

            void mid() {
                lcd.setCursor(0, 0);
                lcd.write(1);
                lcd.setCursor(15, 0);
                lcd.write(2);
                lcd.setCursor(0, 1);
                lcd.setCursor(1, 0);
                lcd.print("     MID      ");
                lcd.print("      -.-       ");
            }

            void maxi() {
                lcd.setCursor(0, 0);
                lcd.write(1);
                lcd.setCursor(15, 0);
                lcd.write(2);
                lcd.setCursor(0, 1);
                lcd.setCursor(1, 0);
                lcd.print("     MAX      ");
                lcd.print("      -.-       ");
            }

            void calib() {
                lcd.setCursor(0, 0);
                lcd.write(1);
                lcd.setCursor(15, 0);
                lcd.write(2);
                lcd.setCursor(1, 0);
                lcd.print("  RECALIBRATE ");
                lcd.setCursor(0, 1);
                lcd.print("BACK          OK");
            }
            void save() {
                lcd.setCursor(0, 0);
                lcd.write(1);
                lcd.setCursor(15, 0);
                lcd.write(2);
                lcd.setCursor(1, 0);
                lcd.print("     SAVE     ");
                lcd.setCursor(0, 1);
                lcd.print("BACK          OK");
            }
        }
    }


    namespace settingOption {
        void pid() {
            lcd.setCursor(0, 0);
            lcd.write(1);
            lcd.setCursor(15, 0);
            lcd.write(2);
            lcd.setCursor(1, 0);
            lcd.print("      PID     ");
            lcd.setCursor(0, 1);
            lcd.print("BACK          OK");
        }
        void speed() {
            lcd.setCursor(0, 0);
            lcd.write(1);
            lcd.setCursor(15, 0);
            lcd.write(2);
            lcd.setCursor(1, 0);
            lcd.print("     SPEED    ");
            lcd.setCursor(0, 1);
            lcd.print("BACK   ");
            lcd.setCursor(10, 1);
            lcd.print("    OK");
            lcd.setCursor(7, 1);
            lcd.print("-.-");
        }
        void fanSpeed() {
            lcd.setCursor(0, 0);
            lcd.write(1);
            lcd.setCursor(15, 0);
            lcd.write(2);
            lcd.setCursor(1, 0);
            lcd.print("    FANSPEED  ");
            lcd.setCursor(0, 1);
            lcd.print("BACK   ");
            lcd.setCursor(10, 1);
            lcd.print("    OK");
            lcd.setCursor(7, 1);
            lcd.print("-.-");
        }
        void led() {
            lcd.setCursor(0, 0);
            lcd.write(1);
            lcd.setCursor(15, 0);
            lcd.write(2);
            lcd.setCursor(1, 0);
            lcd.print("      LED     ");
            lcd.setCursor(0, 1);
            lcd.print("BACK   ");
            lcd.setCursor(10, 1);
            lcd.print("    OK");
            lcd.setCursor(7, 1);
            lcd.print("-.-");
        }
        void sound() {
            lcd.setCursor(0, 0);
            lcd.write(1);
            lcd.setCursor(15, 0);
            lcd.write(2);
            lcd.setCursor(1, 0);
            lcd.print("     SOUND    ");
            lcd.setCursor(0, 1);
            lcd.print("BACK    ");
            lcd.setCursor(9, 1);
            lcd.print("     OK");
            lcd.setCursor(8, 1);
            lcd.print("1");
        }
    }

    namespace pidVal {
        void kp() {
            lcd.setCursor(0, 0);
            lcd.write(1);
            lcd.setCursor(15, 0);
            lcd.write(2);
            lcd.setCursor(1, 0);
            lcd.print("       Kp     ");
            lcd.setCursor(0, 1);
            lcd.print("BACK");
            lcd.setCursor(13, 1);
            lcd.print(" OK");
            lcd.setCursor(4, 1);
            lcd.print("----.----");
        }

        void kd() {
            lcd.setCursor(0, 0);
            lcd.write(1);
            lcd.setCursor(15, 0);
            lcd.write(2);
            lcd.setCursor(1, 0);
            lcd.print("       Kd     ");
            lcd.setCursor(0, 1);
            lcd.print("BACK");
            lcd.setCursor(13, 1);
            lcd.print(" OK");
            lcd.setCursor(4, 1);
            lcd.print("----.----");
        }

        void ki() {
            lcd.setCursor(0, 0);
            lcd.write(1);
            lcd.setCursor(15, 0);
            lcd.write(2);
            lcd.setCursor(1, 0);
            lcd.print("       Ki     ");
            lcd.setCursor(0, 1);
            lcd.print("BACK");
            lcd.setCursor(13, 1);
            lcd.print(" OK");
            lcd.setCursor(4, 1);
            lcd.print("----.----");
        }
    }


    byte button() {
        byte but = 0;
        bool s1v = digitalRead(s1),
            s2v = digitalRead(s2),
            s3v = digitalRead(s3),
            s4v = digitalRead(s4),
            s5v = digitalRead(s5),
            s6v = digitalRead(s6),
            s7v = digitalRead(s7),
            s8v = digitalRead(s8);

        if (s1v != 0 && s1v == 1) but += pow(2, 0);
        else if (s2v != (prevBut & (byte)pow(2, 1)) && s2v == 1) but += pow(2, 1);
        else if (s3v != (prevBut & (byte)pow(2, 2)) && s3v == 1) but += pow(2, 2);
        else if (s4v != (prevBut & (byte)pow(2, 3)) && s4v == 1) but += pow(2, 3);
        else if (s5v != (prevBut & (byte)pow(2, 4)) && s5v == 1) but += pow(2, 4);
        else if (s6v != (prevBut & (byte)pow(2, 5)) && s6v == 1) but += pow(2, 5);
        else if (s7v != (prevBut & (byte)pow(2, 6)) && s7v == 1) but += pow(2, 6);
        else if (s8v != (prevBut & (byte)pow(2, 7)) && s8v == 1) but += pow(2, 7);


        return but;
    }






    void run() {

        byte butVal = button();
        byte curCmd = (~butVal) & (prevBut);
        prevBut = butVal;

        if (state == 0 && curCmd == 1 && prevCmd != 1) {
            state++;
            prevCmd = curCmd;
        }
        if (state >= 1) {
            if (state == 1) welcome();

            if (state == 1 && curCmd == 1 && prevCmd != 1) {
                state = 3;
                prevCmd = curCmd;
            }
            if (state == 1 && curCmd == 2 && prevCmd != 2) {
                state = 0;
                prevCmd = curCmd;
            }



            if ((state >> 1) != 0) {

                if ((state >> 3) == 0) {
                    byte mainOptionIndex = state >> 1;
                    if (curCmd == 4 && prevCmd != 4) {
                        mainOptionIndex++;
                        prevCmd = curCmd;
                    }
                    if (curCmd == 8 && prevCmd != 8) {
                        mainOptionIndex--;
                        prevCmd = curCmd;
                    }
                    if (mainOptionIndex <= 0) mainOptionIndex = 3;
                    else if (mainOptionIndex > 3) mainOptionIndex = 1;
                    insert = 3 << 1;
                    insert = ~insert;
                    state = state & insert;
                    state += (mainOptionIndex << 1);
                    if (curCmd == 2 && prevCmd != 2) {
                        state = 1;
                        prevCmd = curCmd;
                    }
                }


                if ((state >> 1) == 1) mainOption::start();
                else if ((state >> 1) == 2) mainOption::calib();
                else if ((state >> 1) == 3) mainOption::setting();

                insert = 3 << 1;
                insert = insert & state;
                insert >>= 1;
                if (insert == 1) {

                    if (state == 3 && curCmd == 1 && prevCmd != 1) {
                        state += pow(2, 3);
                        prevCmd = curCmd;
                        time = millis();
                    }
                    insert = 7 << 3;
                    byte startOptionIndex = ((insert & state) >> 3);
                    if (startOptionIndex != 0 && state > 3) {

                        if (running == 0 && time + 5000 < millis()) {
                            if (startOptionIndex != 1 && startOptionIndex != 2 && curCmd == 4 && prevCmd != 4) {
                                startOptionIndex++;
                                prevCmd = curCmd;
                            }
                            if (startOptionIndex != 1 && startOptionIndex != 2 && curCmd == 8 && prevCmd != 8) {
                                startOptionIndex--;
                                prevCmd = curCmd;
                            }
                            if (startOptionIndex < 3) startOptionIndex = 4;
                            else if (startOptionIndex > 4) startOptionIndex = 3;
                            if (curCmd == 1 && prevCmd != 1) {
                                startOptionIndex = 1;
                                prevCmd = curCmd;
                                time = millis();
                            }

                        }
                        else if (running == 1 && time + 4000 < millis()) startOptionIndex = 2;
                        else if (running == 0) {
                            if (curCmd == 1 && prevCmd != 1) {
                                startOptionIndex = 1;
                                prevCmd = curCmd;
                                time = millis();
                            }
                        }


                        insert = 7 << 3;
                        insert = ~insert;
                        state = state & insert;
                        state += (startOptionIndex << 3);
                        if (startOptionIndex == 1) {
                            commonScreen::loading();
                        }
                        else if (startOptionIndex == 2) startOption::runData();
                        else if (startOptionIndex == 3) startOption::finalData();
                        else if (startOptionIndex == 4) startOption::trace();
                        if (startOptionIndex != 1 && startOptionIndex != 2) {
                            if (curCmd == 2 && prevCmd != 2) {
                                state = 3;
                                prevCmd = curCmd;
                            }
                        }
                    }

                }
                else if (insert == 2) {
                    if ((state >> 3) == 0) {
                        if (curCmd == 1 && prevCmd != 1) {
                            state += 8;
                            prevCmd = curCmd;
                        }
                    }
                    else {
                        if ((state >> 5) == 0) {
                            insert = 3 << 3;
                            insert &= state;
                            byte calibOptionIndex = insert >> 3;
                            if (curCmd == 4 && prevCmd != 4) {
                                calibOptionIndex++;
                                prevCmd = curCmd;
                            }
                            else if (curCmd == 8 && prevCmd != 8) {
                                calibOptionIndex--;
                                prevCmd = curCmd;
                            }
                            if (calibOptionIndex > 2) calibOptionIndex = 1;
                            else if (calibOptionIndex < 1) calibOptionIndex = 2;

                            insert = 3 << 3;
                            insert = ~insert;
                            state = state & insert;
                            state += (calibOptionIndex << 3);

                            if (calibOptionIndex == 1) calibOption::curData();
                            else if (calibOptionIndex == 2) calibOption::newData();


                            if (state >> 5 == 0 && state >> 3 != 0) {
                                if (curCmd == 2 && prevCmd != 2) {
                                    state = 5;
                                    prevCmd = curCmd;
                                }
                            }
                            if (calibOptionIndex == 1) {
                                if (curCmd == 1 && prevCmd != 1) {
                                    state = 45;
                                    prevCmd = curCmd;
                                }
                                else if (calibOptionIndex == 2) {
                                    if (curCmd == 1 && prevCmd != 1) {
                                        state = 77;
                                        prevCmd = curCmd;
                                    }
                                }
                            }
                            else {
                                insert = state >> 3;
                                insert &= 3;


                                if (insert == 1) {

                                    insert = 7 << 5;
                                    insert &= state;
                                    byte currentDataIndex = insert >> 5;
                                    if (state >> 5 == 0) {
                                        if (curCmd == 1 && prevCmd != 1) {
                                            state += pow(2, 5);
                                            currentDataIndex = 1;
                                            prevCmd = curCmd;
                                        }
                                    }
                                    else {

                                        if (curCmd == 4 && prevCmd != 4) {
                                            currentDataIndex++;
                                            prevCmd = curCmd;
                                        }
                                        else if (curCmd == 8 && prevCmd != 8) {
                                            currentDataIndex--;
                                            prevCmd = curCmd;
                                        }
                                        if (currentDataIndex < 1) currentDataIndex = 4;
                                        else if (currentDataIndex > 4) currentDataIndex = 1;

                                        insert = 7 << 5;
                                        insert = ~insert;
                                        state &= insert;
                                        state += (currentDataIndex << 5);

                                        if (currentDataIndex == 1) calibOption::calibData::mini();
                                        else if (currentDataIndex == 2) calibOption::calibData::mid();
                                        else if (currentDataIndex == 3) calibOption::calibData::maxi();
                                        else if (currentDataIndex == 4) calibOption::calibData::calib();
                                    }
                                }
                            }
                        }
                    }

                }
                else if (insert == 3) {
                    if (state >> 3 == 0) {
                        if (curCmd == 1 && prevCmd != 1) {
                            state += (1 << 3);
                            prevCmd = curCmd;
                        }
                    }
                    else {

                        insert = 7 << 3;
                        insert = state & insert;

                        byte settingOptionIndex = insert >> 3;
                        if (state >> 6 == 0) {
                            if (curCmd == 4 && prevCmd != 4) {
                                settingOptionIndex++;
                                prevCmd = curCmd;
                            }
                            else if (curCmd == 8 && prevCmd != 8) {
                                settingOptionIndex--;
                                prevCmd = curCmd;
                            }
                            if (settingOptionIndex < 1) settingOptionIndex = 5;
                            if (settingOptionIndex > 5) settingOptionIndex = 1;
                            insert = 7 << 3;
                            insert = ~insert;
                            state = state & insert;
                            state += (settingOptionIndex << 3);

                            if ((state >> 6) == 0) {
                                if (curCmd == 2 && prevCmd != 2) {
                                    state = 7;
                                    prevCmd = curCmd;
                                }
                            }
                            if (state >> 6 == 0) {
                                if (settingOptionIndex == 1) {
                                    settingOption::pid();
                                }
                                else if (settingOptionIndex == 2) {
                                    settingOption::speed();
                                }
                                else if (settingOptionIndex == 3) {
                                    settingOption::fanSpeed();
                                }
                                else if (settingOptionIndex == 4) {
                                    settingOption::led();
                                }
                                else if (settingOptionIndex == 5) {
                                    settingOption::sound();
                                }
                            }
                        }

                        if (state >> 6 == 0) {
                            if (settingOptionIndex == 1 && curCmd == 1 && prevCmd != 1) {
                                state += (1 << 6);
                                prevCmd = curCmd;
                            }
                        }
                        else if (state >> 6 != 0) {
                            insert = 3 << 6;
                            insert &= state;
                            byte pidOptionIndex = insert >> 6;



                            if (curCmd == 4 && prevCmd != 4) {
                                pidOptionIndex++;
                                prevCmd = curCmd;
                            }
                            else if (curCmd == 8 && prevCmd != 8) {
                                pidOptionIndex--;
                                prevCmd = curCmd;
                            }

                            Serial.print(pidOptionIndex);
                            Serial.print("\t");

                            if (pidOptionIndex > 3) pidOptionIndex = 1;
                            else if (pidOptionIndex < 1) pidOptionIndex = 3;

                            insert = 3 << 6;
                            insert = ~insert;
                            state = state & insert;
                            state += (pidOptionIndex << 6);



                            if (pidOptionIndex == 1) pidVal::kp();
                            else if (pidOptionIndex == 2) pidVal::kd();
                            else if (pidOptionIndex == 3) pidVal::ki();
                            if (curCmd == 2 && prevCmd != 2) {
                                state = 15;
                                prevCmd = curCmd;
                            }
                        }
                    }
                }
            }

        }
        else {
            //lcd.clear();
            commonScreen::gadiNikal();
        }

        prevCmd = curCmd;
    }



}

void setup() {

    display::init();
    Serial.begin(9600);
}

void loop() {

    display::run();
    Serial.println(display::state);
    //display::settingOption::sound();
}

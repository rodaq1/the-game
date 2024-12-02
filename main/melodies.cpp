#include <buzzer.cpp>

void playGameStartMelody(Buzzer buzzer) {
    uint32_t melody[7] = {
        NOTE_C4, NOTE_E4, NOTE_G4, NOTE_C5, NOTE_G4, NOTE_E4, NOTE_C4
    };

    uint32_t duration[7] = {
        500, 500, 500, 1000, 500, 500, 2000
    };

    int size = sizeof(melody) / sizeof(melody[0]); 

    for (int i = 0; i < size; i++) {
        buzzer.playTone(melody[i], duration[i]);
    }
}

void playSuccessMelody(Buzzer &buzzer) {
    uint32_t melody[2] = {
        NOTE_C5, NOTE_E5
    };
    uint32_t duration[2] = {
        200, 400
    };

    for (int i = 0; i < 2; i++) {
        buzzer.playTone(melody[i], duration[i]);
    }
}

void playGameOverMelody(Buzzer buzzer) {
    uint32_t melody[8] = {
        NOTE_C4, NOTE_G3, NOTE_E3, NOTE_A3, NOTE_B3, NOTE_A3, NOTE_G3, NOTE_C3
    };

    uint32_t duration[8] = {
        500, 500, 500, 500, 1000, 500, 500, 2000
    };

    int size = sizeof(melody) / sizeof(melody[0]); 

    for (int i = 0; i < size; i++) {
        buzzer.playTone(melody[i], duration[i]);
    }
}

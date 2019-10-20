
#include QMK_KEYBOARD_H
#define KC_OSX_EJECT 0x66
#define LOCK_OSX LSFT(LCTL(KC_OSX_EJECT))
#define SLEEP_OSX LALT(LGUI(KC_OSX_EJECT))

enum custom_keycodes {
  RANDOM_STRING = SAFE_RANGE
};

const char *strings[] = {
  "CLACK!",
  "Is it webscale?",
  "I know boats!",
  "Salt User Do...",
  "Not with that attitude. (TM)",
  "If you die in Minecraft do you die in real life?",
  "What is the Matrix?",
  "By the way, I use Arch Linux.",
  "Have you tried turning it off and on?",
  "hunter2",
  "Exuse the tyypos, I'm tyyping on ann Apple kyboarrd.",
  "Segmentation fault.",
  "Guru Meditation Error",
  "Reticulating splines.",
  "The Cylons might strike at any time.",
  "So say we all!",
  "Sarah Connor?",
  "Life uh... finds a way.",
  "Hold on to your butts.",
  "It's a UNIX system! I know this!",
  "Blockchain!",
  "This is my endgame keyboard.",
  "PC LOAD LETTER",
  "Enter any 11-digit prime number to continue.",
  "E-mail returned to sender, insufficient voltage.",
  "Hack the planet!",
  "There are 2 hard problems in computer science: cache invalidation, naming things, and off-by-1 errors.",
  "Install Gentoo!",
  "House Red!",
  "Containers you say! http://doger.io",
  "My other keyboard is a Planck.",
  "This is fine.",
  "0118 999 881 999 119 7253",
  "While you were partying, I studied the blade.",
  "SET BLASTER=A220 I5 D1 H5 P330 E620 T6",
  "Everyone should design their own font. It's character building.",
  "Honk!",
  "Knock, knock, Neo.",
  "Switch SCE to AUX.",
  "It's pronounced JIF.",
  "What does the fox say?",
  "Low-level programming is good for the programmer's soul. - John Carmack",
  "QMK Inside.",
  "Machines take me by surprise with great frequency. - Alan Turing",
  "It's Megalodon!",
  "Shall we play a game?",
  "Greetings, Professor Falken.",
  "WAIT6502,1",
  "telnet towel.blinkenlights.nl",
  "Gentlemen, you can't fight in here! This is the war room!",
  "Hello. My name is Inigo Montoya. You killed my father. Prepare to die.",
  "All your base are belong to us",
  "Education never ends, Watson. It is a series of lessons with the greatest for the last. - Sherlock Holmes",
  "Cherry MX Reds in the streets, Cherry MX Greens in the sheets.", // bad joke is bad
  "Guns make you stupid; better to fight your wars with duct tape. Duct tape makes you smart.",
  "Allan please add details.",
};

const int strings_count = sizeof(strings) / sizeof(strings[0]);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static int current_index = strings_count;

  if (record->event.pressed) {
    if (current_index == strings_count) {
      srand(timer_read());
      current_index = 0;
      // Fisher - Yates shuffle
      for (int i = strings_count - 1; i > 0; --i) {
        int j = rand() % (i + 1);

        const char * tmp = strings[i];
        strings[i] = strings[j];
        strings[j] = tmp;
      }
    }
    switch(keycode) {
      case RANDOM_STRING:
        send_string(strings[current_index]);
        SEND_STRING(" #bbs\n");
        current_index += 1;
        return false;
    }
  }
  return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  LAYOUT(RANDOM_STRING),
};

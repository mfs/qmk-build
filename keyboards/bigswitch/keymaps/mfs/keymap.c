
#include QMK_KEYBOARD_H
#define KC_OSX_EJECT 0x66
#define LOCK_OSX LSFT(LCTL(KC_OSX_EJECT))
#define SLEEP_OSX LALT(LGUI(KC_OSX_EJECT))

enum custom_keycodes {
  RANDOM_STRING = SAFE_RANGE
};

const char *strings[] = {
  "CLACK!\n",
  "Is it webscale?\n",
  "I know boats!\n",
  "Salt User Do...\n",
  "Not with that attitude. (TM)\n",
  "If you die in Minecraft do you die in real life?\n",
  "What is the Matrix?\n",
  "By the way, I use Arch Linux.\n",
  "Have you tried turning it off and on?\n",
  "hunter2\n",
  "Exuse the tyypos, I'm tyyping on ann Apple kyboarrd.\n",
  "Segmentation fault.\n",
  "Guru Meditation Error\n",
  "Reticulating splines.\n",
  "The Cylons might strike at any time.\n",
  "So say we all!\n",
  "Sarah Connor?\n",
  "Life uh... finds a way.\n",
  "Hold on to your butts.\n",
  "It's a UNIX system! I know this!\n",
  "Blockchain!\n",
  "This is my endgame keyboard.\n",
  "PC LOAD LETTER\n",
  "Enter any 11-digit prime number to continue.\n",
  "E-mail returned to sender, insufficient voltage.\n",
  "Hack the planet!\n",
  "There are 2 hard problems in computer science: cache invalidation, naming things, and off-by-1 errors.\n",
  "Install Gentoo!\n",
  "House Red!\n",
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    int strings_count = sizeof(strings) / sizeof(strings[0]);
    int i = rand() % strings_count;
    switch(keycode) {
      case RANDOM_STRING:
        send_string(strings[i]);
        return false;
    }
  }
  return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  LAYOUT(RANDOM_STRING),
};

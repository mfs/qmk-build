
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
  "Hack the planet!\n",
  "Containers you say! http://doger.io\n",
  "My other keyboard is a Planck.\n",
  "This is fine.\n",
  "0118 999 881 999 119 7253\n",
  "While you were partying, I studied the blade.\n",
  "SET BLASTER=A220 I5 D1 H5 P330 E620 T6\n",
  "Everyone should design their own font. It's character building.\n",
  "Honk!\n",
  "Knock, knock, Neo.\n",
  "Switch SCE to AUX.\n",
  "It's pronounced JIF.\n",
  "What does the fox say?\n",
  "Low-level programming is good for the programmer's soul. - John Carmack\n",
  "QMK Inside.\n",
  "Machines take me by surprise with great frequency. - Alan Turing\n",
  "It's Megalodon!\n",
  "Shall we play a game?\n",
  "Greetings, Professor Falken.\n",
  "WAIT6502,1\n",
  "telnet towel.blinkenlights.nl\n",
  "Gentlemen, you can't fight in here! This is the war room!\n",
  "Hello. My name is Inigo Montoya. You killed my father. Prepare to die.\n",
  "All your base are belong to us\n",
  "Education never ends, Watson. It is a series of lessons with the greatest for the last. - Sherlock Holmes\n",
  "Cherry MX Reds in the streets, Cherry MX Greens in the sheets.\n", // bad joke is bad
  "Guns make you stupid; better to fight your wars with duct tape. Duct tape makes you smart.\n",
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
        current_index += 1;
        return false;
    }
  }
  return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  LAYOUT(RANDOM_STRING),
};

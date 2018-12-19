void butt_check(){

    if (kpd.getKeys())
    {
        for (int i=0; i<LIST_MAX; i++)   // Scan the whole key list.
        {
            if ( kpd.key[i].stateChanged )   // Only find keys that have changed state.
            {
                switch (kpd.key[i].kstate) {  // Report active key state : IDLE, PRESSED, HOLD, or RELEASED
                    case PRESSED:
                    Keyboard.press(kpd.key[i].kchar);
                break;
                    case RELEASED:
                    Keyboard.release(kpd.key[i].kchar);
                }
            }
        }
    }
}

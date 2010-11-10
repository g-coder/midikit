#include "test.h"
#include "midi/message.h"

int test001_message( void ) {
   struct MIDIMessage * message = MIDIMessageCreate( MIDI_STATUS_NOTE_OFF );
   unsigned char buffer[8] = { 0 };
   ASSERT( message != NULL, "Could not create note off message." );
   ASSERT( MIDIMessageSet( message, MIDI_KEY, 60 ) == 0, "Could not set key." );
   ASSERT( MIDIMessageSet( message, MIDI_CHANNEL, MIDI_CHANNEL_1 ) == 0, "Could not set channel." );
   ASSERT( MIDIMessageSet( message, MIDI_VELOCITY, 127 ) == 0, "Could not set velocity." );
   ASSERT( MIDIMessageRead( message, 8, &buffer[0] ) == 0, "Could not read MIDI data from message." );
   ASSERT( buffer[0] == 0x80, "Read wrong status / channel byte!" );
   ASSERT( buffer[1] == 60,   "Read wrong key byte!" );
   ASSERT( buffer[2] == 127,  "Read wrong velocity byte!" );
   ASSERT( buffer[3] == 0,    "Trailing data in message!" );
   MIDIMessageRelease( message );
   return 0;
}

int test002_message( void ) {
   struct MIDIMessage * message = MIDIMessageCreate( 0x81 );
   ASSERT( message == NULL, "Can create MIDI message with invalid status." );
   MIDIMessageRelease( message );
   return 0;
}

int test003_message( void ) {
   struct MIDIMessage * message = MIDIMessageCreate( MIDI_STATUS_NOTE_ON );
   unsigned char buffer[8] = { 0 };
   ASSERT( message != NULL, "Could not create note on message." );
   ASSERT( MIDIMessageSet( message, MIDI_KEY, 60 ) == 0, "Could not set key." );
   return 0;
}
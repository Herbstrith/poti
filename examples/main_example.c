/*
    This file is part of Poti

    Poti is free software: you can redistribute it and/or modify
    it under the terms of the GNU Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Poti is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Public License for more details.

    You should have received a copy of the GNU Public License
    along with Poti. If not, see <http://www.gnu.org/licenses/>.
*/
#include <poti.h>

int main (int argc, char **argv)
{
  //first, dump the pajeheader
  //first parameter is a boolean indicating a basic header or not
  //second parameter is a boolean indicating an old header or not
  poti_init(POTI_TEXT, "output.paje", 0, 0);
  //int new_push_state_identifier = poti_header_PajePushState (old_header, "Mark", PAJE_string);

  //Defining my types
  poti_DefineContainerType ("ROOT", "0", "ROOT");

  poti_DefineContainerType("THREAD", "ROOT", "THREAD");
  poti_DefineStateType("STATE", "THREAD", "STATE");
  poti_DefineLinkType("LINK", "ROOT", "THREAD", "THREAD", "LINK");

  //define values and color for the STATE type
  poti_DefineEntityValue("r", "STATE", "running", "0.0 1.0 0.0");
  poti_DefineEntityValue("i", "STATE", "idle", "0.3 0.3 0.3");

  //define values and color for the LINK type
  poti_DefineEntityValue("c", "LINK", "communication", "1 0 0");

  //Create my root container and containers for two threads
  poti_CreateContainer (0.01, "root", "ROOT", "0", "root");
  poti_CreateContainer (0.12, "thread-0", "THREAD", "root", "thread-0");
  poti_CreateContainer (0.23, "thread-1", "THREAD", "root", "thread-1");
  
  //Start a link from thread-0
  poti_StartLink (0.24, "root", "LINK", "thread-0", "c", "myKey-001");

  //Push and Pop two states for each thread
  poti_PushState (0.34, "thread-0", "STATE", "r");
  poti_PushState (0.45, "thread-1", "STATE", "r");
  poti_PopState  (0.56, "thread-0", "STATE");
  poti_PushState (0.67, "thread-0", "STATE", "i");
  poti_PopState  (0.78, "thread-1", "STATE");
  poti_PushState (0.89, "thread-1", "STATE", "i");
  poti_PopState  (0.90, "thread-0", "STATE");
  poti_PopState  (1.01, "thread-1", "STATE");

  //poti_UserPushState (new_push_state_identifier, 0.34, "thread-0", "STATE", "r", "valor_do_mark");

  //End the link at thread-1
  poti_EndLink (1.02, "root", "LINK", "thread-1", "c", "myKey-001");

  //Closing containers
  poti_DestroyContainer (1.12, "THREAD", "thread-0");
  poti_DestroyContainer (1.23, "THREAD", "thread-1");
  poti_DestroyContainer (1.34, "ROOT", "root");

  poti_close ();

  return 0;


}

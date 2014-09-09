/*
    This file is part of PajeNG

    PajeNG is free software: you can redistribute it and/or modify
    it under the terms of the GNU Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    PajeNG is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Public License for more details.

    You should have received a copy of the GNU Public License
    along with PajeNG. If not, see <http://www.gnu.org/licenses/>.
*/
#include "PajeTraceEvent.h"

PajeTraceEvent::PajeTraceEvent (PajeEventDefinition *def, paje_line *line)
{
  if (line->word_count != def->fieldCount()){
    std::stringstream st;
    st << *line;
    std::string lreport = st.str();
    std::cout << *def << std::endl;
    std::cout << "Line field count: " << line->word_count << std::endl;
    std::cout << "Definition field count: " << def->fieldCount() << std::endl;
    std::cout << "Field count does not match definition for line "+lreport << std::endl;
    exit(1);
  }
  valueLine = line;
  pajeEventDefinition = def;
}

PajeEventId PajeTraceEvent::pajeEventId (void)
{
  return pajeEventDefinition->pajeEventIdentifier;
}

std::string PajeTraceEvent::valueForField (PajeField field)
{
  int index = pajeEventDefinition->indexForField (field);
  if (index == -1){
    return std::string("");
  }else{
    return std::string(valueLine->word[index]);
  }
}

std::string PajeTraceEvent::valueForExtraField (std::string fieldName)
{
  int index = pajeEventDefinition->indexForExtraFieldNamed (fieldName);
  if (index == -1){
    return std::string("");
  }else{
    return std::string(valueLine->word[index]);
  }
}

long long PajeTraceEvent::getLineNumber (void) const
{
  return valueLine->lineNumber;
}

std::string PajeTraceEvent::description (void) const
{
  std::stringstream output;
  unsigned int i;
  output << "(Line: " << valueLine->lineNumber;
  output << ", Fields: '" << valueLine->word_count;
  output << ", Contents: '";
  for (i = 0; i < valueLine->word_count; i++){
    output << std::string(valueLine->word[i]);
    if (i+1 != valueLine->word_count) output << " ";
  }
  output << "')";
  return output.str();
}

std::ostream &operator<< (std::ostream &output, const PajeTraceEvent &event)
{
  output << event.description();
  return output;
}

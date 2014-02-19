#!/bin/bash

MINE=./tube7
PROF=/user/cse450/Public/Project7/tube7
VIRTUAL=/user/cse450/Public/TubeCode/tubecode
INPUT=tests/*.tube

rm -f *.diff
echo -n "Running tests"
echo
for FILE in $INPUT
do
  echo -n $FILE
  echo
  $MINE $FILE mine.out &> mine.err
  $PROF $FILE prof.out &> prof.err

  $VIRTUAL mine.out &> mine.ac.out
  $VIRTUAL prof.out &> prof.ac.out

  NAME=$(basename "$FILE")
  TYPE=`echo $NAME | cut -c1-4`
  if [ $TYPE == "good" ] ; then
    MINE_DIFF=mine.ac.out
    PROF_DIFF=prof.ac.out
  else
    MINE_DIFF=mine.err
    PROF_DIFF=prof.err
  fi

  DIFF=$NAME.diff
  if diff -u $MINE_DIFF $PROF_DIFF > $DIFF ; then
    rm $DIFF
    PASS=("${PASS[@]}" "$NAME")
  else
    FAIL=("${FAIL[@]}" "$NAME")
  fi
  rm mine.out prof.out mine.ac.out prof.ac.out mine.err prof.err 2> /dev/null
done
echo "Finished"

printf "\n\nPassed ${#PASS[@]} Tests: "
printf "%s, " "${PASS[@]}" | cut -d "," -f 1-${#PASS[@]}
printf "\nFailed ${#FAIL[@]} Tests: "
printf "%s, " "${FAIL[@]}" | cut -d "," -f 1-${#FAIL[@]}


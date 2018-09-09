echo "Running unit tests:"

for i in tests/*_tests
do
  if test -f
  then
    if $VALGRIND ./$i >> tests/tests.log
    then
      echo $i PASS
    else
      echo "ERROR in test $i: here's tests/tests.log"
      echo "-------"
      tail tests/tests.log
      exit 1
    fi
  fi
done

echo ""

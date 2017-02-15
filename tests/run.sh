#!/bin/bash
set -o errexit -o nounset -o pipefail

esc="$(printf '\033')"
checkmark="${esc}[32m✔${esc}[0m"
crossmark="${esc}[31m✘${esc}[0m"
this_dir="$(dirname "$0")"
errors=0

for source_file in $(find "$this_dir" -name "*_test.re")
do
  test_name="${source_file/%_test.re/}"
  expected_file="${test_name}"_expected.js
  actual_file=lib/js/"${test_name}"_test.js

  if diff -q "$expected_file" "$actual_file"
  then
    echo "$checkmark Files $expected_file and $actual_file match." >&2
  else
    echo "$checkmark Files $expected_file and $actual_file do not match." >&2
    diff -u "$expected_file" "$actual_file"
    errors=$((errors + 1))
  fi
done

exit "$errors"

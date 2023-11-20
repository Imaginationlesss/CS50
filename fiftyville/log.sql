-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Seeing description of crime scene on 28th of july 2021 on Humphrey Street
SELECT description FROM crime_scene_reports WHERE day = 28 AND month = 7 AND street LIKE "Humphrey%";

--Checking the transcripts from interviews where bakery is mentioned
SELECT transcript FROM interviews WHERE day = 28 AND month = 7 AND year = 2021;

--Checking secutiry logs to get more information about car that thief left with
SELECT activity, license_plate FROM bakery_security_logs WHERE day = 28 AND month = 7 AND year = 2021 AND hour = 10 AND minute BETWEEN 15 AND 25;

-- Checking names of people with same license plates as the people who left bakery after theft
SELECT DISTINCT name FROM people
JOIN bakery_security_logs
ON people.license_plate = bakery_security_logs.license_plate
WHERE people.license_plate IN
 (SELECT license_plate
 FROM bakery_security_logs
 WHERE day = 28
 AND month = 7
 AND year = 2021
 AND hour = 10
 AND minute BETWEEN 15 AND 25);

 --Cheking phone numbers of callers and receiver who left the bakery after theft
 SELECT caller, receiver FROM phone_calls WHERE day = 28 AND month = 7 AND year = 2021 AND duration < 60;

 --Checking Names that we checked with license plates with the caller phone_numbers
SELECT name FROM people
WHERE name IN
 (SELECT DISTINCT name FROM people
 JOIN bakery_security_logs
 ON people.license_plate = bakery_security_logs.license_plate
 WHERE people.license_plate IN
  (SELECT license_plate
  FROM bakery_security_logs
  WHERE day = 28
  AND month = 7
  AND year = 2021
  AND hour = 10
  AND minute BETWEEN 15 AND 25))
  AND phone_number IN
   ( SELECT caller FROM phone_calls
   WHERE day = 28
   AND month = 7
   AND year = 2021
   AND duration < 60);

--Getting names of people receiving calls
SELECT name FROM people
WHERE phone_number IN
 (SELECT receiver FROM phone_calls
 WHERE caller IN
  (SELECT caller FROM phone_calls
  WHERE day = 28
  AND month = 7
  AND year = 2021
  AND duration < 60))
  AND name IN
   (SELECT DISTINCT name FROM people
   JOIN bakery_security_logs
   ON people.license_plate = bakery_security_logs.license_plate
   WHERE people.license_plate IN
    (SELECT license_plate
    FROM bakery_security_logs
    WHERE day = 28
    AND month = 7
    AND year = 2021
    AND hour = 10
    AND minute BETWEEN 15 AND 25));

--Getting id for Fiftyville airport
SELECT id from airports WHERE city = "Fiftyville";

--Getting destination airport id
SELECT destination_airport_id, hour, minute FROM flights WHERE origin_airport_id = 8 AND day = 29 AND month = 7 AND year = 2021 ORDER BY hour, minute ASC LIMIT 1;

--Getting Name of the City thief is going
SELECT DISTINCT city FROM airports
JOIN flights ON flights.destination_airport_id = airports.id
WHERE flights.destination_airport_id IN
 (SELECT destination_airport_id FROM flights
 WHERE origin_airport_id = 8
 AND day = 29
 AND month = 7
 AND year = 2021
 ORDER BY hour, minute ASC
 LIMIT 1);

--Finding account number which thief used
SELECT account_number FROM atm_transactions
WHERE atm_location = "Leggett Street"
AND transaction_type = "withdraw"
AND day = 28
AND month = 7
AND year = 2021;

--Getting person id
SELECT person_id FROM bank_accounts
WHERE account_number IN
 (SELECT account_number FROM atm_transactions
WHERE atm_location = "Leggett Street"
AND transaction_type = "withdraw"
AND day = 28
AND month = 7);

--Getting name of the people who get withdraw from atm and matches license plate numbers as well as caller number
SELECT name FROM people
JOIN bank_accounts ON bank_accounts.person_id = people.id
WHERE bank_accounts.person_id IN
 (SELECT person_id FROM bank_accounts
 WHERE account_number IN
  (SELECT account_number FROM atm_transactions
  WHERE atm_location = "Leggett Street"
  AND transaction_type = "withdraw"
  AND day = 28
  AND month = 7))
  AND name IN
  (SELECT name FROM people WHERE phone_number IN
 (SELECT caller FROM phone_calls
WHERE caller IN
 (SELECT phone_number
FROM people WHERE name IN
 (SELECT name FROM people
 JOIN bakery_security_logs
 ON people.license_plate = bakery_security_logs.license_plate
 WHERE people.license_plate IN
  (SELECT license_plate
  FROM bakery_security_logs
  WHERE day = 28
  AND month = 7
  AND year = 2021
  AND hour = 10
  AND minute BETWEEN 15 AND 25))
  AND license_plate IN
   (SELECT license_plate
   FROM bakery_security_logs
   WHERE day = 28
   AND month = 7
   AND year = 2021
   AND hour = 10
   AND minute BETWEEN 15 AND 25))
   AND day = 28
   AND month = 7
   AND year = 2021
   AND duration < 60));


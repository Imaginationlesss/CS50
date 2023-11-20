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

 --Cheking phone numbers who left the bakery after theft
 SELECT caller, receiver FROM phone_calls WHERE day = 28 AND month = 7 AND year = 2021 AND duration < 60;

 --Checking which number are for which person with the license plate that we already checked
SELECT phone_number
FROM people WHERE name IN
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
  AND license_plate IN
   (SELECT license_plate
   FROM bakery_security_logs
   WHERE day = 28
   AND month = 7
   AND year = 2021
   AND hour = 10
   AND minute BETWEEN 15 AND 25);

--Comparing the phone numbers of callers of specific information close to our suspect to the ones with the same name license plate numbers and name to distinguish the caller aka thief
SELECT DISTINCT caller, receiver FROM phone_calls
WHERE caller IN
 (SELECT phone_number
FROM people WHERE name IN
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
   AND duration < 60;

--Getting names of people who had phone calls after theft with specific time and length range who also left bakery withing ten minutes after theft
SELECT name FROM people WHERE phone_number IN
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
   AND duration < 60);

--Getting names of people receiving calls
SELECT name FROM people WHERE phone_number IN
 (SELECT receiver FROM phone_calls
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
   AND duration < 60);

--Getting passport numbers of 4 suspercts
SELECT passport_number FROM people WHERE name IN (SELECT name FROM people WHERE phone_number IN
 (SELECT DISTINCT caller FROM phone_calls
WHERE caller IN
 (SELECT phone_number
FROM people WHERE name IN
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
  AND license_plate IN
   (SELECT license_plate
   FROM bakery_security_logs
   WHERE day = 28
   AND month = 7
   AND year = 2021
   AND hour = 10
   AND minute BETWEEN 15 AND 25)) AND day = 28 AND month = 7 AND year = 2021 AND duration < 60));

--Getting id for Fiftyville airport
SELECT id from airports WHERE city = "Fiftyville";

--Getting destination airport id
SELECT id, destination_airport_id, hour, minute FROM flights WHERE origin_airport_id = 8 AND day = 29 AND month = 7 AND year = 2021 ORDER BY hour, minute ASC LIMIT 1;

--Getting Name of the City thief is going
SELECT city FROM airports WHERE id = 4;

--Finding the thief on specific flight with passpoert number matching suspects
SELECT seat from passengers WHERE flight_id IN
 (SELECT id FROM flights
 WHERE origin_airport_id = 8
 AND destination_airport_id = 4
 AND day = 29
 AND month = 7
 AND year = 2021
 AND hour = 8
 AND minute = 20)
 AND passport_number IN
   (SELECT passport_number
   FROM people WHERE name IN
    (SELECT name FROM people WHERE phone_number IN
     (SELECT DISTINCT caller FROM phone_calls
     WHERE caller IN
      (SELECT phone_number
      FROM people WHERE name IN
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
         AND duration < 60)));


SELECT account_number FROM atm_transactions
WHERE atm_location = "Leggett Street"
AND transaction_type = "withdraw"
AND day = 28
AND month = 7
AND year = 2021;

SELECT 

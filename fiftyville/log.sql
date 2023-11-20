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
 SELECT caller, receiver FROM phone_calls WHERE day = 28 AND month = 7 AND year = 2021 AND duration < 600;

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






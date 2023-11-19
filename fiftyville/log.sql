-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Seeing description of crime scene on 28th of july 2021 on Humphrey Street
SELECT description FROM crime_scene_reports WHERE day = 28 AND month = 7 AND street LIKE "Humphrey%";

--Checking the transcripts from interviews where bakery is mentioned
SELECT transcript FROM interviews WHERE day = 28 AND month = 7 AND year = 2021;

--Checking secutiry logs to get more information about car that thief left with


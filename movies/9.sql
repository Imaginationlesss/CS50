SELECT DISTINCT name FROM people
JOIN stars ON people.id = stars.person_id
JOIN movies ON stars.movie_id = movies.id
AND year = "2014"
ORDER BY people.birth ASC;

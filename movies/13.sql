SELECT name FROM people JOIN stars ON stars.person_id = people.id JOIN movies ON stars.movie_id = movies.id WHERE people.name = "Kevin Bacon" AND people.birth = "1958"

SELECT DISTINCT name FROM people
JOIN stars ON stars.person_id = people.id
JOIN movies ON stars.movie_id = movies.id
WHERE movies.id IN (SELECT movies.id FROM movies JOIN stars ON movies.id = stars.movie_id JOIN people ON stars.person_id = people.id WHERE people.name IN ("Kevin Bacon") AND people.birth = "1958");

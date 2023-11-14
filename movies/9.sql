SELECT DISTINCT people.name FROM people, stars, movies
WHERE people.id = stars.movie_id
AND stars.movie_id = movies.id
AND year = "2014"
ORDER BY people.birth;

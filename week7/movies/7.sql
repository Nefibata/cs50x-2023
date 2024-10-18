SELECT movies.title, ratings.rating FROM movies , ratings where ratings.movie_id = movies.id and  ratings.rating IS NOT NULL
AND movies.year = 2010
ORDER BY ratings.rating DESC, movies.title ASC;

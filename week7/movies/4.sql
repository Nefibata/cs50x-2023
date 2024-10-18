SELECT COUNT(title) FROM movies , ratings where  ratings.movie_id = movies.id and rating = 10.0;

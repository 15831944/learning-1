-- insert data into the database each time the system starts
INSERT INTO author (id, first_name, last_name) VALUES (1, 'Alex', 'Antonov')
INSERT INTO publisher (id, name) VALUES (2, 'Pack')
INSERT INTO book (id, isbn, title, description, author_id, publisher_id) VALUES (3, '978-1-78528-415-1', 'Spring Boot Recipes', 'The recipes for Sprint', 1, 2)
CREATE TABLE new_students (
    id INTEGER NOT NULL,
    student TEXT NOT NULL,
    PRIMARY KEY(id)
);

CREATE TABLE houses (
    id INTEGER NOT NULL,
    house TEXT NOT NULL,
    head TEXT NOT NULL,
    PRIMARY KEY(id)
);

CREATE TABLE house_assigment (
    id INTEGER NOT NULL,
    student TEXT NOT NULL,
    house TEXT NOT NULL,
    PRIMARY KEY(id)
);

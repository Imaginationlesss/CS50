CREATE TABLE new_students (
    id INTEGER,
    student_name TEXT,
    PRIMARY KEY(id)
);

CREATE TABLE houses (
    id INTEGER,
    house TEXT,
    head TEXT,
    PRIMARY KEY(id)
);

CREATE TABLE house_assaigment (
    id INTEGER,
    student_name TEXT,
    house TEXT,
    PRIMARY KEY(id)
);

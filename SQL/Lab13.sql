-- 1
-- a
CREATE TABLE ANGAJATI_AMI (
    COD_ANG NUMBER(4),
    NUME VARCHAR2(20),
    PRENUME VARCHAR2(20),
    EMAIL CHAR(15),
    DATA_ANG DATE DEFAULT SYSDATE,
    JOB VARCHAR2(10),
    COD_SEF NUMBER(4),
    SALARIU NUMBER(8, 2),
    COD_DEP NUMBER(2)
);
DROP TABLE ANGAJATI_AMI;

-- b
CREATE TABLE ANGAJATI_AMI (
    COD_ANG NUMBER(4) PRIMARY KEY,
    NUME VARCHAR2(20) NOT NULL,
    PRENUME VARCHAR2(20),
    EMAIL CHAR(15),
    DATA_ANG DATE DEFAULT SYSDATE,
    JOB VARCHAR2(10),
    COD_SEF NUMBER(4),
    SALARIU NUMBER(8, 2) NOT NULL,
    COD_DEP NUMBER(2)
);
DROP TABLE ANGAJATI_AMI;

-- c
CREATE TABLE ANGAJATI_AMI (
    COD_ANG NUMBER(4),
    NUME VARCHAR2(20) NOT NULL,
    PRENUME VARCHAR2(20),
    EMAIL CHAR(15),
    DATA_ANG DATE DEFAULT SYSDATE,
    JOB VARCHAR2(10),
    COD_SEF NUMBER(4),
    SALARIU NUMBER(8, 2) NOT NULL,
    COD_DEP NUMBER(2),
    PRIMARY KEY(COD_ANG)
);
DROP TABLE ANGAJATI_AMI;

-- 2
INSERT INTO ANGAJATI_AMI(COD_ANG, NUME, PRENUME, DATA_ANG, JOB, SALARIU, COD_DEP)
VALUES (100, 'Nume1', 'Prenume1', NULL, 'Director', 20000, 10);

INSERT INTO ANGAJATI_AMI
VALUES (101, 'Nume2', 'Prenume2', 'Nume2', to_date('02-02-2004', 'dd-mm-yyyy'), 'Inginer', 100, 10000, 10);

INSERT INTO ANGAJATI_AMI
VALUES (102, 'Nume3', 'Prenume3', 'Nume3', to_date('05-06-2000', 'dd-mm-yyyy'), 'Analist', 101, 5000, 20);

INSERT INTO ANGAJATI_AMI
VALUES (103, 'Nume4', 'Prenume4', NULL, NULL, 'Inginer', 100, 9000, 20);

INSERT INTO ANGAJATI_AMI(COD_ANG, NUME, PRENUME, DATA_ANG, JOB, COD_SEF, SALARIU, COD_DEP)
VALUES (104, 'Nume4', 'Prenume4', NULL, 'Inginer', 100, 9000, 20);

COMMIT;

-- 3
CREATE TABLE ANGAJATI10_AMI
AS SELECT * FROM ANGAJATI_AMI WHERE COD_DEP = 10;
-- S-A PIERDUT CONSTRANGEREA DE PK

-- 4
ALTER TABLE ANGAJATI_AMI
ADD (COMISION NUMBER(4, 2));

-- 5
ALTER TABLE ANGAJATI_AMI
MODIFY (SALARIU NUMBER(6, 2));
-- NU SE POATE MICSORA DIMENSIUNEA UNEI COLOANE CARE CONTINE VALORI NENULE

-- 6
ALTER TABLE ANGAJATI_AMI
MODIFY (SALARIU DEFAULT 5000);

-- 7
ALTER TABLE ANGAJATI_AMI
MODIFY (
    COMISION NUMBER(2, 2),
    SALARIU NUMBER(10, 2)
);

-- 8
SELECT * FROM ANGAJATI_AMI;
UPDATE ANGAJATI_AMI
SET COMISION = 0.1
WHERE UPPER(JOB) LIKE 'A%';

-- 9
ALTER TABLE ANGAJATI_AMI
MODIFY (EMAIL VARCHAR2(15));

-- 10
ALTER TABLE ANGAJATI_AMI
ADD (NR_TELEFON VARCHAR(15) DEFAULT '000.000.0000');

-- 11
SELECT * FROM ANGAJATI_AMI;

ALTER TABLE ANGAJATI_AMI
DROP COLUMN NR_TELEFON;

-- 12
RENAME ANGAJATI_AMI TO ANGAJATI3_AMI;

-- 13
SELECT * FROM TAB;

RENAME ANGAJATI3_AMI TO ANGAJATI_AMI;

-- 14
TRUNCATE TABLE ANGAJATI10_AMI;

-- 15
CREATE TABLE DEPARTAMENTE_AMI (
    COD_DEP NUMBER(2),
    NUME VARCHAR2(15) NOT NULL,
    COD_DIRECTOR NUMBER(4)
);
DESC DEPARTAMENTE_AMI;

-- 16
INSERT INTO DEPARTAMENTE_AMI
VALUES (10, 'Administrativ', 100);

INSERT INTO DEPARTAMENTE_AMI
VALUES (20, 'Proiectare', 101);

INSERT INTO DEPARTAMENTE_AMI
VALUES (30, 'Programare', NULL);

-- 17
ALTER TABLE DEPARTAMENTE_AMI
MODIFY (COD_DEP CONSTRAINT PK_DEP_AMI PRIMARY KEY);

-- 18
-- a
ALTER TABLE ANGAJATI_AMI
ADD CONSTRAINT FK_COD_DEP FOREIGN KEY(COD_DEP) REFERENCES DEPARTAMENTE_AMI(COD_DEP);

-- b
DROP TABLE ANGAJATI_AMI;

CREATE TABLE ANGAJATI_AMI (
    COD_ANG NUMBER(4) CONSTRAINT PK_COD_ANG_AMI PRIMARY KEY,
    NUME VARCHAR2(20) CONSTRAINT NNL_NUME_AMI NOT NULL,
    PRENUME VARCHAR2(20),
    EMAIL CHAR(15) CONSTRAINT UNQ_EMAIL_AMI UNIQUE,
    DATA_ANG DATE DEFAULT SYSDATE,
    JOB VARCHAR2(10),
    COD_SEF NUMBER(4),
    SALARIU NUMBER(8, 2) NOT NULL,
    COD_DEP NUMBER(2) CONSTRAINT FK_COD_DEP_AMI REFERENCES DEPARTAMENTE_AMI(COD_DEP) CONSTRAINT CK_GR_0  CHECK (COD_DEP > 0),
    COMISION NUMBER(2, 2),
    CONSTRAINT FK_COD_SEF_AMI FOREIGN KEY(COD_SEF) REFERENCES ANGAJATI_AMI(COD_ANG),
    CONSTRAINT UNQ_NUME_PRENUME_AMI UNIQUE(NUME, PRENUME),
    CONSTRAINT CK_SAL_AMI CHECK(SALARIU > COMISION * 100)
);

-- 24
ALTER TABLE ANGAJATI_AMI
ADD CONSTRAINT NNL_EMAIL_AMI CHECK(EMAIL IS NOT NULL);

-- 25
-- NU SE POATE DEOARECE COD_DEP ESTE FK PT COED_DEP IN DEPARTAMENTE_AMI SI NU EXISTA UN DEPARTAMENT CU CODUL 50

-- 26
INSERT INTO DEPARTAMENTE_AMI
VALUES (60, 'Analiza', NULL);

-- 27
DELETE FROM DEPARTAMENTE_AMI
WHERE COD_DEP = 20;

-- 31
ALTER TABLE ANGAJATI_AMI
DROP CONSTRAINT FK_COD_DEP_AMI;

ALTER TABLE ANGAJATI_AMI
ADD CONSTRAINT FK_COD_DEP_AMI FOREIGN KEY(COD_DEP) REFERENCES DEPARTAMENTE_AMI(COD_DEP) ON DELETE CASCADE;

-- 33
ALTER TABLE DEPARTAMENTE_AMI
ADD CONSTRAINT FK_COD_DIR_AMI FOREIGN KEY(COD_DIRECTOR) REFERENCES ANGAJATI_AMI(COD_ANG) ON DELETE SET NULL;

-- 35
ALTER TABLE ANGAJATI_AMI
ADD CONSTRAINT CK_SAL_MAX_AMI CHECK(SALARIU < 30000);
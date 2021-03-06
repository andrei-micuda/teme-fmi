-- LAB 10
-- RECAP
-- 1
SELECT D.DEPARTMENT_NAME NUME_DEP, E.LAST_NAME NUME_ANG
FROM DEPARTMENTS D FULL OUTER JOIN EMPLOYEES E ON (D.DEPARTMENT_ID = E.DEPARTMENT_ID);

-- 2
SELECT
    E.EMPLOYEE_ID ID_ANG,
    E.LAST_NAME NUME_ANG,
    TO_CHAR(E.HIRE_DATE, 'DD-MM-YYYY') DATA_ANG,
    TO_CHAR(E.SALARY / 1.2, '9999.99') SAL_ANG,
    TO_DATE('01-06-2010', 'DD-MM-YYYY') - E.HIRE_DATE DIF_ZILE,
    D.DEPARTMENT_NAME NUME_DEP
FROM EMPLOYEES E, DEPARTMENTS D
WHERE E.DEPARTMENT_ID = D.DEPARTMENT_ID;

-- 3
SELECT
    PHONE_NUMBER NR_VECHI,
    SUBSTR(PHONE_NUMBER, 1, 4) || DECODE(SUBSTR(PHONE_NUMBER, 5, 3), '123', '033', SUBSTR(PHONE_NUMBER, 5, 3)) || SUBSTR(PHONE_NUMBER, 8) NR_NOU
FROM EMPLOYEES;

-- 1
CREATE TABLE EMP_AMI
AS SELECT * FROM EMPLOYEES;

CREATE TABLE DEPT_AMI
AS SELECT * FROM DEPARTMENTS;

-- 2
DESC EMPLOYEES;
DESC EMP_AMI;

DESC DEPT_AMI;
DESC DEPARTMENTS;
-- SE PIERD CONSTRANGERILE DE CHEIE PRIMARA/EXTERNA

-- 3
SELECT * FROM EMP_AMI;
SELECT * FROM DEPT_AMI;

-- 4
ALTER TABLE EMP_AMI
ADD CONSTRAINT PK_EMP_AMI PRIMARY KEY(EMPLOYEE_ID);
DESC EMP_AMI; -- ACUM SI EMPLOYEE_ID ESTE "NOT NULL"

ALTER TABLE DEPT_AMI
ADD CONSTRAINT PK_DEPT_AMI PRIMARY KEY(DEPARTMENT_ID);
DESC DEPT_AMI;

ALTER TABLE EMP_AMI
ADD CONSTRAINT FK_DEPT_AMI FOREIGN KEY(DEPARTMENT_ID) REFERENCES DEPT_AMI(DEPARTMENT_ID);

-- 5
-- a
INSERT INTO DEPT_AMI
VALUES (300, 'Programare');
-- NU S-AU SPECIFICAT COLOANELE PE CARE SE FACE INSERT, TREBUIE SA DAM EXPLICIT VALORI TUTUROR COLOANELOR

-- b
INSERT INTO DEPT_AMI (department_id, department_name)
VALUES (300, 'Programare');
ROLLBACK;

-- c
INSERT INTO DEPT_AMI (department_name, department_id)
VALUES (300, 'Programare');
-- TIPURILE COLOANELOR NU CORESPUND CU TIPURILE VALORILOR INTRODUSE

-- d
INSERT INTO DEPT_AMI (department_id, department_name, location_id)
VALUES (300, 'Programare', null);
ROLLBACK;

-- e
INSERT INTO DEPT_AMI (department_name, location_id)
VALUES ('Programare', null);
-- LOCATION_ID ARE CONSTRANGERE DE "NOT NULL"

-- 6
DESC EMP_AMI;
INSERT INTO EMP_AMI
VALUES(250, NULL, 'Micuda', 'andrei.micuda@gmail.com', NULL, SYSDATE - 1, 'SA_REP', NULL, NULL, NULL, 300);
COMMIT;

-- 7
INSERT INTO EMP_AMI(EMPLOYEE_ID, FIRST_NAME, LAST_NAME, EMAIL, HIRE_DATE, JOB_ID, DEPARTMENT_ID)
VALUES(251, 'Adina', 'Borta', 'adina.borta@gmail.com', SYSDATE, 'SA_REP', 300);
COMMIT;

-- 8
INSERT INTO EMP_AMI (employee_id, last_name, email, hire_date, job_id, salary,
commission_pct)
VALUES (252, 'Nume252', 'nume252@emp.com',SYSDATE, 'SA_REP', 5000, NULL);

SELECT employee_id, last_name, email, hire_date, job_id, salary, commission_pct
FROM emp_AMI
WHERE employee_id=252;
ROLLBACK;

INSERT INTO
(SELECT employee_id, last_name, email, hire_date, job_id, salary,
commission_pct
FROM emp_AMI)
VALUES (252, 'Nume252', 'nume252@emp.com',SYSDATE, 'SA_REP', 5000, NULL);

SELECT employee_id, last_name, email, hire_date, job_id, salary, commission_pct
FROM emp_AMI
WHERE employee_id=252;
ROLLBACK;

INSERT INTO EMP_AMI (EMPLOYEE_ID, LAST_NAME, EMAIL, HIRE_DATE, JOB_ID, SALARY, DEPARTMENT_ID)
VALUES ((SELECT MAX(EMPLOYEE_ID) + 1 FROM EMP_AMI), 'Nume1000', 'nume252@emp.com',SYSDATE, 'SA_REP', 5000, NULL);
COMMIT;

-- 9
-- VAR 1
CREATE TABLE EMP1_AMI
AS SELECT * FROM EMPLOYEES
    WHERE COMMISSION_PCT > 0.25;
DROP TABLE EMP1_AMI;

-- VAR 2
CREATE TABLE EMP1_AMI
AS SELECT * FROM EMPLOYEES;

TRUNCATE TABLE EMP1_AMI;

INSERT INTO EMP1_AMI
SELECT * FROM EMPLOYEES
WHERE COMMISSION_PCT > 0.25;

COMMIT;

INSERT INTO EMP1_AMI
SELECT *
FROM EMPLOYEES
WHERE
    SALARY = (SELECT MAX(SALARY) FROM EMPLOYEES)
    OR SALARY = (SELECT MIN(SALARY) FROM EMPLOYEES);

-- 10
INSERT INTO EMP_AMI
VALUES (0, USER, USER, 'TOTAL', 'TOTAL', SYSDATE, 'TOTAL', (SELECT SUM(SALARY) FROM EMPLOYEES), (SELECT AVG(COMMISSION_PCT) FROM EMPLOYEES), NULL, NULL);

-- 11
INSERT INTO EMP_AMI(EMPLOYEE_ID, LAST_NAME, FIRST_NAME, SALARY, EMAIL, HIRE_DATE, JOB_ID)
VALUES (&id, '&&nume', '&&prenume', &salariu, (SUBSTR('&prenume', 1, 1) || SUBSTR('&nume', 1, 7)), SYSDATE, 'SA_REP');
UNDEF nume;
UNDEF prenume;

-- 14
UPDATE EMP_AMI
SET SALARY = SALARY * 1.05;
SELECT * FROM EMP_AMI;
ROLLBACK;

-- 15
UPDATE EMP_AMI
SET JOB_ID = 'SA_REP'
WHERE
    DEPARTMENT_ID = 80
    AND COMMISSION_PCT IS NOT NULL;
ROLLBACK;
    
-- 16
UPDATE DEPT_AMI
SET MANAGER_ID = (SELECT EMPLOYEE_ID
                FROM EMPLOYEES
                WHERE UPPER(LAST_NAME) = 'GRANT'
                AND UPPER(FIRST_NAME) = 'DOUGLAS')
WHERE DEPARTMENT_ID = 20;

UPDATE EMP_AMI
SET SALARY = SALARY + 1000
WHERE UPPER(LAST_NAME) = 'GRANT'
AND UPPER(FIRST_NAME) = 'DOUGLAS';

-- 17
UPDATE EMP_AMI
SET (SALARY, COMMISSION_PCT) = (SELECT SALARY, COMMISSION_PCT
                                FROM EMP_AMI
                                WHERE EMPLOYEE_ID = (SELECT MANAGER_ID
                                                    FROM EMP_AMI
                                                    WHERE SALARY = (SELECT MIN(SALARY) FROM EMP_AMI)))
WHERE EMPLOYEE_ID = (SELECT EMPLOYEE_ID
                    FROM EMP_AMI
                    WHERE SALARY = (SELECT MIN(SALARY) FROM EMP_AMI));
                   
-- 18
UPDATE EMP_AMI
SET EMAIL = SUBSTR(LAST_NAME, 1, 1) || NVL(FIRST_NAME, '.')
WHERE (DEPARTMENT_ID, SALARY) IN (SELECT DEPARTMENT_ID, MAX(SALARY) FROM EMP_AMI GROUP BY DEPARTMENT_ID);
ROLLBACK;

-- 19
UPDATE EMP_AMI
SET SALARY = (SELECT AVG(SALARY) FROM EMP_AMI)
WHERE (HIRE_DATE, DEPARTMENT_ID) IN (SELECT MIN(HIRE_DATE), DEPARTMENT_ID FROM EMP_AMI GROUP BY DEPARTMENT_ID);

-- 20
UPDATE EMP_AMI
SET (JOB_ID, DEPARTMENT_ID) = (SELECT JOB_ID, DEPARTMENT_ID FROM EMP_AMI WHERE EMPLOYEE_ID = 205)
WHERE EMPLOYEE_ID = 114;

-- 21
DESC DEPT_AMI;
SELECT * FROM DEPT_AMI
WHERE DEPARTMENT_ID = &&id_dep;
UPDATE DEPT_AMI
SET
    DEPARTMENT_NAME = '&nume',
    MANAGER_ID = &manager,
    LOCATION_ID = &id_locatie
WHERE DEPARTMENT_ID = &id_dep;
UNDEF id_dep;

-- 22
DELETE FROM DEPT_AMI;
-- CHEIA PRIMARA ESTE REFERENTIATA IN ALT TABEL

-- 23
DELETE FROM EMP_AMI
WHERE COMMISSION_PCT IS NULL;
ROLLBACK;

-- 24
DELETE FROM DEPT_AMI
WHERE DEPARTMENT_ID IN (SELECT DEPARTMENT_ID FROM DEPT_AMI MINUS SELECT DEPARTMENT_ID FROM EMP_AMI);

DELETE FROM DEPT_AMI
WHERE DEPARTMENT_ID NOT IN (SELECT UNIQUE DEPARTMENT_ID FROM EMP_AMI WHERE DEPARTMENT_ID IS NOT NULL);

-- 25
SELECT *
FROM EMP_AMI
WHERE EMPLOYEE_ID = &&cod_ang;

DELETE FROM EMP_AMI
WHERE EMPLOYEE_ID = &cod_ang;

UNDEF cod_ang;

-- 28
SAVEPOINT P;

-- 29
DELETE FROM EMP_AMI;
SELECT * FROM EMP_AMI;

-- 30
ROLLBACK TO P;

--31
SELECT * FROM EMP_AMI;
COMMIT;
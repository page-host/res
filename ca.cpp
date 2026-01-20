# HR Schema PL/SQL – 8 Questions and Answers (Copyable)

---

## Q1. Write a PL/SQL procedure to increase salary by 10% for a given employee (HR schema).

**Answer:**

```sql
CREATE OR REPLACE PROCEDURE emp_salary_inc (
  p_emp_id employees.employee_id%TYPE
)
AS
BEGIN
  UPDATE employees
  SET salary = salary * 1.10
  WHERE employee_id = p_emp_id;

  DBMS_OUTPUT.PUT_LINE('Salary updated successfully');
END;
/
```

---

## Q2. Write a procedure to display employee name and salary using EMPLOYEE_ID.

**Answer:**

```sql
CREATE OR REPLACE PROCEDURE emp_details (
  p_emp_id employees.employee_id%TYPE
)
AS
  v_name   employees.first_name%TYPE;
  v_salary employees.salary%TYPE;
BEGIN
  SELECT first_name, salary
  INTO v_name, v_salary
  FROM employees
  WHERE employee_id = p_emp_id;

  DBMS_OUTPUT.PUT_LINE('Name: ' || v_name);
  DBMS_OUTPUT.PUT_LINE('Salary: ' || v_salary);
END;
/
```

---

## Q3. Write a procedure to add commission to an employee.

**Answer:**

```sql
CREATE OR REPLACE PROCEDURE add_commission (
  p_emp_id employees.employee_id%TYPE
)
AS
BEGIN
  UPDATE employees
  SET commission_pct = 0.10
  WHERE employee_id = p_emp_id;

  DBMS_OUTPUT.PUT_LINE('Commission added');
END;
/
```

---

## Q4. Write a procedure to display all employees of a department using a cursor.

**Answer:**

```sql
DECLARE
  CURSOR c_emp IS
    SELECT first_name, job_id
    FROM employees
    WHERE department_id = 60;
BEGIN
  FOR rec IN c_emp LOOP
    DBMS_OUTPUT.PUT_LINE(rec.first_name || ' - ' || rec.job_id);
  END LOOP;
END;
/
```

---

## Q5. Write a procedure to count employees in a department.

**Answer:**

```sql
CREATE OR REPLACE PROCEDURE emp_count (
  p_dept_id departments.department_id%TYPE
)
AS
  v_count NUMBER;
BEGIN
  SELECT COUNT(*)
  INTO v_count
  FROM employees
  WHERE department_id = p_dept_id;

  DBMS_OUTPUT.PUT_LINE('Total Employees: ' || v_count);
END;
/
```

---

## Q6. Write a procedure to display highest salary in a department.

**Answer:**

```sql
CREATE OR REPLACE PROCEDURE max_salary (
  p_dept_id departments.department_id%TYPE
)
AS
  v_salary employees.salary%TYPE;
BEGIN
  SELECT MAX(salary)
  INTO v_salary
  FROM employees
  WHERE department_id = p_dept_id;

  DBMS_OUTPUT.PUT_LINE('Highest Salary: ' || v_salary);
END;
/
```

---

## Q7. Write a procedure to display employees hired after a given date.

**Answer:**

```sql
CREATE OR REPLACE PROCEDURE hired_after (
  p_date DATE
)
AS
BEGIN
  FOR rec IN (SELECT first_name, hire_date FROM employees WHERE hire_date > p_date)
  LOOP
    DBMS_OUTPUT.PUT_LINE(rec.first_name || ' - ' || rec.hire_date);
  END LOOP;
END;
/
```

---

## Q8. Why do we use %TYPE in PL/SQL?

**Answer:**
`%TYPE` is used to declare a variable with the same datatype as a table column. It ensures datatype consistency and avoids errors if the column datatype changes.

**Example:**

```sql
v_salary employees.salary%TYPE;
```

---

---

## Q9. Write a procedure to display employee name and department name using JOIN.

**Answer:**

```sql
CREATE OR REPLACE PROCEDURE emp_dept_info (
  p_emp_id employees.employee_id%TYPE
)
AS
  v_name employees.first_name%TYPE;
  v_dept departments.department_name%TYPE;
BEGIN
  SELECT e.first_name, d.department_name
  INTO v_name, v_dept
  FROM employees e
  JOIN departments d ON e.department_id = d.department_id
  WHERE e.employee_id = p_emp_id;

  DBMS_OUTPUT.PUT_LINE('Employee: ' || v_name);
  DBMS_OUTPUT.PUT_LINE('Department: ' || v_dept);
END;
/
```

---

## Q10. Write a procedure to increase salary by a given percentage.

**Answer:**

```sql
CREATE OR REPLACE PROCEDURE inc_salary_pct (
  p_emp_id employees.employee_id%TYPE,
  p_pct NUMBER
)
AS
BEGIN
  UPDATE employees
  SET salary = salary + (salary * p_pct / 100)
  WHERE employee_id = p_emp_id;

  DBMS_OUTPUT.PUT_LINE('Salary increased');
END;
/
```

---

## Q11. Write a procedure to display employees whose salary is above department average.

**Answer:**

```sql
DECLARE
  CURSOR c_emp IS
    SELECT first_name, salary
    FROM employees e
    WHERE salary > (
      SELECT AVG(salary)
      FROM employees
      WHERE department_id = e.department_id
    );
BEGIN
  FOR rec IN c_emp LOOP
    DBMS_OUTPUT.PUT_LINE(rec.first_name || ' : ' || rec.salary);
  END LOOP;
END;
/
```

---

## Q12. Write a procedure to handle NO_DATA_FOUND exception.

**Answer:**

```sql
CREATE OR REPLACE PROCEDURE find_employee (
  p_emp_id employees.employee_id%TYPE
)
AS
  v_name employees.first_name%TYPE;
BEGIN
  SELECT first_name
  INTO v_name
  FROM employees
  WHERE employee_id = p_emp_id;

  DBMS_OUTPUT.PUT_LINE('Employee: ' || v_name);
EXCEPTION
  WHEN NO_DATA_FOUND THEN
    DBMS_OUTPUT.PUT_LINE('Employee not found');
END;
/
```

---

## Q13. Write a procedure using implicit cursor attributes.

**Answer:**

```sql
CREATE OR REPLACE PROCEDURE update_dept_salary (
  p_dept_id departments.department_id%TYPE
)
AS
BEGIN
  UPDATE employees
  SET salary = salary * 1.05
  WHERE department_id = p_dept_id;

  DBMS_OUTPUT.PUT_LINE(SQL%ROWCOUNT || ' rows updated');
END;
/
```

---

## Q14. Write a procedure to delete an employee record.

**Answer:**

```sql
CREATE OR REPLACE PROCEDURE delete_employee (
  p_emp_id employees.employee_id%TYPE
)
AS
BEGIN
  DELETE FROM employees
  WHERE employee_id = p_emp_id;

  DBMS_OUTPUT.PUT_LINE('Employee deleted');
END;
/
```

---

## Q15. Explain the difference between implicit and explicit cursors.

**Answer:**

* Implicit cursor: Automatically created by Oracle for DML and single-row SELECT
* Explicit cursor: Defined by programmer for multi-row SELECT

---

## Q16. Write a procedure using cursor FOR loop.

**Answer:**

```sql
CREATE OR REPLACE PROCEDURE list_employees (
  p_dept_id departments.department_id%TYPE
)
AS
BEGIN
  FOR rec IN (
    SELECT first_name, job_id
    FROM employees
    WHERE department_id = p_dept_id
  ) LOOP
    DBMS_OUTPUT.PUT_LINE(rec.first_name || ' - ' || rec.job_id);
  END LOOP;
END;
/
```

---

## Q17. Write a procedure to display total salary of a department.

**Answer:**

```sql
CREATE OR REPLACE PROCEDURE dept_total_salary (
  p_dept_id departments.department_id%TYPE
)
AS
  v_total NUMBER;
BEGIN
  SELECT SUM(salary)
  INTO v_total
  FROM employees
  WHERE department_id = p_dept_id;

  DBMS_OUTPUT.PUT_LINE('Total Salary: ' || v_total);
END;
/
```

---

## Q18. Why is cursor FOR loop preferred?

**Answer:**
Cursor FOR loop is preferred because it automatically opens, fetches, and closes the cursor, reducing errors and code complexity.

---

---

## Q19. Write a procedure to update job_id of an employee.

**Answer:**

```sql
CREATE OR REPLACE PROCEDURE update_job (
  p_emp_id employees.employee_id%TYPE,
  p_job_id employees.job_id%TYPE
)
AS
BEGIN
  UPDATE employees
  SET job_id = p_job_id
  WHERE employee_id = p_emp_id;

  DBMS_OUTPUT.PUT_LINE('Job updated successfully');
END;
/
```

---

## Q20. Write a procedure to transfer an employee to another department.

**Answer:**

```sql
CREATE OR REPLACE PROCEDURE transfer_employee (
  p_emp_id employees.employee_id%TYPE,
  p_dept_id departments.department_id%TYPE
)
AS
BEGIN
  UPDATE employees
  SET department_id = p_dept_id
  WHERE employee_id = p_emp_id;

  DBMS_OUTPUT.PUT_LINE('Employee transferred');
END;
/
```

---

## Q21. Write a procedure to display employees without commission.

**Answer:**

```sql
CREATE OR REPLACE PROCEDURE no_commission_emp
AS
BEGIN
  FOR rec IN (SELECT first_name FROM employees WHERE commission_pct IS NULL)
  LOOP
    DBMS_OUTPUT.PUT_LINE(rec.first_name);
  END LOOP;
END;
/
```

---

## Q22. Write a procedure using WHILE loop to display first N employees.

**Answer:**

```sql
CREATE OR REPLACE PROCEDURE first_n_employees (
  p_n NUMBER
)
AS
  v_count NUMBER := 0;
BEGIN
  FOR rec IN (SELECT first_name FROM employees)
  LOOP
    EXIT WHEN v_count = p_n;
    DBMS_OUTPUT.PUT_LINE(rec.first_name);
    v_count := v_count + 1;
  END LOOP;
END;
/
```

---

## Q23. Write a procedure to check whether an employee exists.

**Answer:**

```sql
CREATE OR REPLACE PROCEDURE check_employee (
  p_emp_id employees.employee_id%TYPE
)
AS
  v_count NUMBER;
BEGIN
  SELECT COUNT(*)
  INTO v_count
  FROM employees
  WHERE employee_id = p_emp_id;

  IF v_count = 0 THEN
    DBMS_OUTPUT.PUT_LINE('Employee does not exist');
  ELSE
    DBMS_OUTPUT.PUT_LINE('Employee exists');
  END IF;
END;
/
```

---

## Q24. Write a procedure to display department-wise employee count.

**Answer:**

```sql
CREATE OR REPLACE PROCEDURE dept_emp_count
AS
BEGIN
  FOR rec IN (
    SELECT department_id, COUNT(*) cnt
    FROM employees
    GROUP BY department_id
  ) LOOP
    DBMS_OUTPUT.PUT_LINE('Dept ' || rec.department_id || ' : ' || rec.cnt);
  END LOOP;
END;
/
```

---

## Q25. Write a procedure to demonstrate COMMIT and ROLLBACK.

**Answer:**

```sql
CREATE OR REPLACE PROCEDURE salary_update_commit (
  p_emp_id employees.employee_id%TYPE
)
AS
BEGIN
  UPDATE employees
  SET salary = salary + 500
  WHERE employee_id = p_emp_id;

  COMMIT;
  DBMS_OUTPUT.PUT_LINE('Salary updated and committed');
END;
/
```

---

## Q26. Write a procedure using SAVEPOINT.

**Answer:**

```sql
CREATE OR REPLACE PROCEDURE salary_savepoint_demo
AS
BEGIN
  UPDATE employees SET salary = salary + 100 WHERE department_id = 10;
  SAVEPOINT sp1;

  UPDATE employees SET salary = salary + 100 WHERE department_id = 20;
  ROLLBACK TO sp1;

  COMMIT;
  DBMS_OUTPUT.PUT_LINE('Savepoint demonstrated');
END;
/
```

---

## Q27. Write a procedure to handle TOO_MANY_ROWS exception.

**Answer:**

```sql
CREATE OR REPLACE PROCEDURE emp_by_job (
  p_job_id employees.job_id%TYPE
)
AS
  v_name employees.first_name%TYPE;
BEGIN
  SELECT first_name
  INTO v_name
  FROM employees
  WHERE job_id = p_job_id;

  DBMS_OUTPUT.PUT_LINE(v_name);
EXCEPTION
  WHEN TOO_MANY_ROWS THEN
    DBMS_OUTPUT.PUT_LINE('More than one employee found');
END;
/
```

---

## Q28. Write a procedure to show SYSDATE and employee hire date difference.

**Answer:**

```sql
CREATE OR REPLACE PROCEDURE emp_experience (
  p_emp_id employees.employee_id%TYPE
)
AS
  v_years NUMBER;
BEGIN
  SELECT FLOOR(MONTHS_BETWEEN(SYSDATE, hire_date)/12)
  INTO v_years
  FROM employees
  WHERE employee_id = p_emp_id;

  DBMS_OUTPUT.PUT_LINE('Experience: ' || v_years || ' years');
END;
/
```

---

## Q29. Write a procedure to insert a new employee.

**Answer:**

```sql
CREATE OR REPLACE PROCEDURE add_employee (
  p_id employees.employee_id%TYPE,
  p_name employees.first_name%TYPE,
  p_job employees.job_id%TYPE,
  p_salary employees.salary%TYPE
)
AS
BEGIN
  INSERT INTO employees (employee_id, first_name, job_id, salary)
  VALUES (p_id, p_name, p_job, p_salary);

  DBMS_OUTPUT.PUT_LINE('Employee inserted');
END;
/
```

---

## Q30. Why should procedures be used in database applications?

**Answer:**
Procedures improve performance, security, reusability, and maintainability by keeping business logic inside the database.

---



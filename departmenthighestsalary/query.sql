SELECT d.name AS 'Department', e.name AS 'Employee', salary
FROM Department d
INNER JOIN Employee e
ON e.departmentId = d.id
INNER JOIN (
	  SELECT departmentId, MAX(salary) as max_salary
	  FROM Employee
	  GROUP BY departmentId
) em
ON e.departmentId = em.departmentId AND e.salary = em.max_salary;


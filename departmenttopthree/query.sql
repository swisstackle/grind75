SELECT d.name AS 'Department', e.name AS 'Employee', e.salary AS 'Salary'
FROM Department d
INNER JOIN Employee e
ON e.departmentId = d.id
INNER JOIN (
	SELECT salary, departmentId, name, DENSE_RANK() OVER (PARTITION BY departmentId ORDER BY salary DESC) AS `rank`
	FROM Employee
) em
ON e.departmentId = em.departmentId
AND em.`rank` <= 3
AND e.name = em.name;

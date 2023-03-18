SELECT e.name AS 'Employee'
FROM Employee e
JOIN Employee s ON e.managerId = s.Id
WHERE e.salary > s.salary

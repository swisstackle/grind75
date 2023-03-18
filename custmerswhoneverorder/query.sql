SELECT name as 'Customers' 
FROM Customers c 
WHERE NOT EXISTS (
	SELECT 1 
	FROM Orders o
	WHERE o.customerId = c.id
);

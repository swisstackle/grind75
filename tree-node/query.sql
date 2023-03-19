SELECT id,
CASE
	WHEN t1.p_id IS null THEN 'Root'
	WHEN (SELECT p_id FROM Tree t2 WHERE t1.id = t2.p_id LIMIT 1) IS NOT NULL THEN 'Inner' ELSE 'Leaf'
	END as 'Type'
FROM Tree t1;


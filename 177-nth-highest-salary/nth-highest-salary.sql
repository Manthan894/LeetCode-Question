CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      SELECT DISTINCT salary
      FROM Employee t1
      WHERE N = (
          SELECT COUNT(DISTINCT t2.salary)
          FROM Employee t2
          WHERE t2.salary >= t1.salary
      )
  );
END
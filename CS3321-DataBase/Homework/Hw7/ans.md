## Problem 1

```sql
CREATE TABLE price_log (
  id INT NOT NULL AUTO_INCREMENT, -- 将主键设为自增，每次加入新的数据的时候id会自动设置为之前最大的id + 1
  product_id INT UNSIGNED NOT NULL,
  price DECIMAL(10,2),
  update_time TIMESTAMP NOT NULL,
  PRIMARY KEY (id),
  FOREIGN KEY (product_id) REFERENCES Product(product_id)
  	ON DELETE CASCADE
  	ON UPDATE CASCADE
);

CREATE TRIGGER price_update 
AFTER UPDATE OF price ON product 
FOR EACH ROW 
WHEN (NEW.price <> OLD.price)  -- 检查新旧价格是否不同
BEGIN
	INSERT INTO price_log (product_id, price, update_time)
	VALUES (OLD.product_id, NEW.price, CURRENT_TIMESTAMP);
END;

```



## Problem 2

```sql
CREATE TRIGGER backup_delete_students 
BEFORE DELETE ON Students 
FOR EACH ROW 
BEGIN
    INSERT INTO student_bf (Sno, Sname, Ssex, Sage, Sdept)
    VALUES (OLD.Sno, OLD.Sname, OLD.Ssex, OLD.Sage, OLD.Sdept);
END;
```



## Problem 3

```sql
CREATE TRIGGER insert_grade
BEFORE INSERT ON sc 

FOR EACH ROW 
BEGIN 
	IF NEW.Grade < 0 THEN 
    SET NEW.Grade = 0; 
    ELSEIF NEW.Grade > 100 THEN 
    SET NEW.Grade = 0; 
	END IF; 
END;
```


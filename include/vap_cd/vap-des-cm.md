; 创建数据库
vap vp0, 0x0
aoc &vp0, "mydb"

; 创建表
vap vp1, 0x1
aoc &vp1, "t_user"

; 创建表字段
beg *v1:

	vap 0x2:
	    mov "username"
	    mov varchar
	    mov 255
	    mov false
	end:add
	
	vap 0x2:
	    mov "password"
	    mov varchar
	    mov 255
	    mov false
	end:add
	
	vap 0x2:
	    mov "age"
	    mov int
	    mov 3
	    mov true ; 是否允许为空
	end:add
	
end

add &vp0, &vp1 ; 将表添加到数据库
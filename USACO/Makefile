.PHONY: clean

clean:
	# -I: include files mentioned in .gitignore
	# -t f: search only for files
	# -x rm: 对搜索结果执行删除
	# Regular Expression
	fd -I -t f "^(main|brute|gen|test|in|out1|out2|stress\.txt|.*\.bin)$$" -x rm
	
	# -t d: search only for directories
	# -H: include hidden files and directories
	fd -HI -t d "^(.*\.dSYM|__pycache__|\.cph)$$" -x rm -rf

	@echo "cleaned"
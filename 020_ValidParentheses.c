bool pair(char firstChar, char secondChar)
{
	if(firstChar == '(' && secondChar == ')' || firstChar == '[' && secondChar == ']' || firstChar == '{' && secondChar == '}')
		return true;
	return false;
}

bool isValid(char* s) 
{
	if(!s)
		return false;
	int size = strlen(s);
	char *stack = (char *)malloc(sizeof(char) * (size + 1));
	int k = 0;
	while(*s != '\0')
	{
		char curChar = *s;
		char prevChar;
		switch(curChar)
		{
			case '(':
			case '[':
			case '{':
				stack[k++] = curChar;
				break;
			case ')':
			case ']':
			case '}':
				prevChar = stack[--k];
				if(pair(prevChar, curChar))
					break;
				else
				{
					free(stack);
					return false;
				}
			default:
			{
				free(stack);
				return false;
			}
		}
		s++;
	}
	
	free(stack);			
	if(k)
		return false;
	return true;
}
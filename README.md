**SlangScript**
<br>
*There are a lot of programming languages out there, but none for the average Gen-Z folk.*
<br>

**Why I made SlangScript:**
I wanted to make programming accessible for those that only understood Gen-Z slang.
<br>

**How did I make SlangScript?:**
Using LLVM, I made a custom compiler with a lexer that scans raw source code and breaks it into a collection of tokens. 
<br>
Each token can be a keywords, literals, identifiers, separators and operators (similar to most popular programming languages like Python or C++).
<br>
Then I created an abstract syntax tree (AST) that represents the actual structure of the code and how those tokens mentioned above relate to each other. 
<br>
Then I wrote a parser to loop over each token and build out the AST.
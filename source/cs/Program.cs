//input 받기
string? input = Console.ReadLine();

//가변 배열
List<int> pointer = [];

//초기 값 넣기
pointer.Add(0);

//위치 변수
int loc = 0;

//루프 위치 변수
List<int> save_loc1 = [];

List<int> save_loc2 = [];


List<int> temporary = [];

int pos = 0;


//null 처리
if(input == string.Empty || input == null){
    Console.WriteLine("입력한 정보가 없습니다");
    Environment.Exit(0);
}

for(int j = 0; j < input.Length; j++)
{
    switch(input[j]){
        case '[':
            temporary.Add(j);
            break;
        case ']':
            if(temporary.Count != 0){
                save_loc1.Add(temporary[temporary.Count - 1]);
                save_loc2.Add(j);
                temporary.RemoveAt(temporary.Count - 1);
            }
            break;
    }
}


//본 구문
for (int i = 0; i < input.Length; i++)
{
    switch (input[i])
    {
        case '+':
            pointer[loc] += 1;
            break;
        case '-':
            pointer[loc] -= 1;
            break;
        case '>':
            loc += 1;
            if (pointer.Count < loc + 1) { pointer.Add(0); }
            break;
        case '<':
            if (loc > 0) { loc -= 1; }
            break;
        case '.':
            Console.Write(Convert.ToChar(pointer[loc]));
            break;
        case '[':
            if (pointer[loc] == 0)
            {
                pos = save_loc1.IndexOf(i);
                i = save_loc2[pos] - 1;
            }
            break;
        case ']':
            if (pointer[loc] != 0)
            {
                pos = save_loc2.IndexOf(i);
                i = save_loc1[pos] - 1;
            }
            break;
    }
}

//마지막 문자 오류 제거
Console.Write(Environment.NewLine);
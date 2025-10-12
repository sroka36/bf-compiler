//input 받기
string? input = Console.ReadLine();

//가변 배열
List<int> pointer = [];

//초기 값 넣기
pointer.Add(0);

//위치 변수
int loc = 0;

int save_loc1 = -1;
int save_loc2 = -1;


if(input == string.Empty || input == null){
    Console.WriteLine("입력한 정보가 없습니다");
    Environment.Exit(0);
}

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
            if (save_loc1 == -1)
            {
                save_loc1 = i;
            }
            if (pointer[loc] == 0)
            {
                i = save_loc2;
                save_loc1 = -1; save_loc2 = -1;
            }
            break;
        case ']':
            if (save_loc2 == -1)
            {
                save_loc2 = i;
            }

            if (pointer[loc] != 0)
            {
                i = save_loc1 - 1;
            }
            break;
    }
}

//마지막 문자 오류 제거
Console.Write(Environment.NewLine);
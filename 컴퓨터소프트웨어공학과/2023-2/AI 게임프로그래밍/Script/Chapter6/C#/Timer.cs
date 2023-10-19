using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Timer : MonoBehaviour
{
    public static float time;  // 정적으로 선언된 시간 변수

    // Start is called before the first frame update
    void Start()
    {
        time = 0;  // 게임 시작 시 시간을 0으로 초기화
    }

    // Update is called once per frame
    void Update()
    {
        if (Goal.goal == false)  // 만약 Goal 클래스에서 goal이 false라면 (목표에 도달하지 않았을 때)
        {
            time += Time.deltaTime;  // 시간을 Time.deltaTime만큼 누적하여 측정 (1초당 호출되는 프레임 속도에 따라)
        }
        int t = Mathf.FloorToInt(time);  // 시간을 정수로 변환 (소수 부분 제거)
        Text uiText = GetComponent<Text>();  // 스크립트가 연결된 게임 오브젝트의 Text 컴포넌트 가져오기
        uiText.text = "Time:" + t;  // 화면에 "Time:"과 현재 시간을 표시
    }
}

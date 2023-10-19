using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class GameResult : MonoBehaviour
{
    private int highScore;     // 최고 점수를 저장하기 위한 변수
    public Text resultTime;    // 결과 시간을 표시할 UI 텍스트 요소
    public Text bestTime;      // 최고 시간을 표시할 UI 텍스트 요소
    public GameObject resultUI; // 결과 화면 UI를 관리하는 게임 오브젝트

    void Start()
    {
        // 만약 "HighScore" 키로 저장된 데이터가 있다면 그 값을 가져옴
        if (PlayerPrefs.HasKey("HighScore"))
        {
            highScore = PlayerPrefs.GetInt("HighScore");
        }
        else
        {
            // 저장된 데이터가 없을 경우 초기 최고 점수를 999로 설정
            highScore = 999;
        }
    }

    void Update()
    {
        // 게임의 목표(Goal)가 달성되었을 때 실행
        if (Goal.goal)
        {
            // 결과 화면을 활성화
            resultUI.SetActive(true);

            // 현재 시간을 정수로 변환하여 결과 시간 텍스트에 표시
            int result = Mathf.FloorToInt(Timer.time);
            resultTime.text = "ResultTime:" + result;

            // 최고 점수를 최고 시간 텍스트에 표시
            bestTime.text = "BestTime:" + highScore;

            // 현재 결과 시간이 최고 점수보다 더 낮으면 최고 점수를 업데이트
            if (highScore > result)
            {
                PlayerPrefs.SetInt("HighScore", result);
            }
        }
    }

    // "Retry" 버튼이 눌렸을 때 호출되는 함수
    public void OnRetry()
    {
        // 현재 장면을 다시 로드하여 게임 재시작
        SceneManager.LoadScene(SceneManager.GetActiveScene().name);
    }
}

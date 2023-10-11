using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DestroyObj : MonoBehaviour
{
    // 게임 오브젝트를 삭제할 시간(초) 변수 선언
    public float deleteTime = 2.0f;

    // Start is called before the first frame update
    void Start()
    {
        // Destroy 메서드를 사용하여 현재 스크립트가 연결된 게임 오브젝트(this.gameObject)를 'deleteTime' 변수에 설정된 시간 후에 삭제합니다.
        // Destroy(삭제할 객체, 설정 시간)
        Destroy(gameObject, deleteTime);
    }

    // Update is called once per frame
    void Update()
    {

    }
}

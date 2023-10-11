using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class HiyokoGenerator : MonoBehaviour
{
    public GameObject obj; // 생성할 게임 오브젝트의 프리팹
    public float interval = 3.0f; // 게임 오브젝트 생성 간격(초)을 설정하는 변수

    // Start is called before the first frame update
    void Start()
    {
        // InvokeRepeating 메서드를 사용하여 "SpawnObj" 메서드를 0.1초 후부터 일정한 간격(interval)으로 반복 실행합니다.
        // InvokeRepeating(반복할 함수, 간격, 반복 방법)
        InvokeRepeating("SpawnObj", 0.1f, interval);
    }

    void SpawnObj()
    {
        // Instantiate 함수를 사용하여 'obj' 변수에 지정된 프리팹을 현재 스크립트가 연결된 게임 오브젝트의 위치(transform.position)와 회전(transform.rotation)에 생성합니다.
        // Instantiate( 생성할 객체, 위치, 회전)
        Instantiate(obj, transform.position, transform.rotation);

        //해당 스크립트를 객체가 생성될 위치 즉, SpawnPoint 에 적용시킨 후 obj에 생성할 객체 프리팹을 적용시키면 SpawnPoint 에서 해당 객체가 반복 생성된다.
    }
}

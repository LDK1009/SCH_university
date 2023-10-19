using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Goal : MonoBehaviour
{
    public static bool goal;

    // Start is called before the first frame update
    void Start()
    {
        goal = false;
    }

    // 트리거 충돌(Trigger collision)이 발생했을 때 호출되는 메소드
    void OnTriggerEnter(Collider col)
    {
        if (col.gameObject.tag == "Player")
        {
            goal = true;
        }
    }
}

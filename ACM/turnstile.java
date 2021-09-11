import java.util.LinkedList;
import java.util.List;

public class Turnsites {
        public int[] getTimes(int[] times, int[] directions) {
            // Store index of the entry or exit time
            List<Integer> entry = new LinkedList<>();
            List<Integer> exit = new LinkedList<>();

            // store the idx for entry or exit times.
            for (int i = 0; i < times.length; i++) {
                if (directions[i] == 0)
                    entry.add(i);
                else 
                    exit.add(i);
            }
            int curTime = -1;
            int prevDir = 1;
            int[] result = new int[times.length];

            // iterate till all the people left
            while (!entry.isEmpty() && !exit.isEmpty()) {
                int curEntryIdx = entry.get(0);
                int curExitIdx = exit.get(0);
                int curEntryTime = Math.max(times[curEntryIdx], curTime);
                int curExitTime = Math.max(times[curExitIdx], curTime);

                if (curEntryTime < curExitTime) {
                    result[curEntryIdx] = curEntryTime;
                    prevDir = 0;
                    entry.remove(0);
                    curTime = curEntryTime + 1;
                } else if (curExitTime < curEntryTime) {
                    result[curExitIdx] = curExitTime;
                    prevDir = 1;
                    exit.remove(0);
                    curTime = curExitTime + 1;
                } else {
                    if (prevDir == 0) {
                        result[curEntryIdx] = curEntryTime;
                        entry.remove(0);
                        curTime = curEntryTime + 1;
                    } else {
                        result[curExitIdx] = curExitTime;
                        exit.remove(0);
                        curTime = curExitTime + 1;                    
                    }
                }
            }

            while (!entry.isEmpty()) {
                int curEntry = entry.remove(0);
                int curEnterTime = Math.max(times[curEntry], curTime);
                result[curEntry] = curEnterTime;
                curTime = curEnterTime + 1;
            }

            while (!exit.isEmpty()) {
                int curExit = exit.remove(0);
                int curExitTime = Math.max(times[curExit], curTime);
                result[curExit] = curExitTime;
                curTime = curExitTime + 1;
            }

            return result;
    }
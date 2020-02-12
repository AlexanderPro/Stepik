public class CheckLabels {
    public Label checkLabels(TextAnalyzer[] analyzers, String text) {
        for (TextAnalyzer analyzer: analyzers) {
            Label label = analyzer.processText(text);
            if (label != Label.OK) return label;
        }

        return Label.OK;
    }
}

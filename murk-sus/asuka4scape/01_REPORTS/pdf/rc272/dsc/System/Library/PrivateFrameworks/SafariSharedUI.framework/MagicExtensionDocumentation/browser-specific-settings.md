# Browser Specific Settings

## Purpose
Include the original user prompt that inspired the extension.

## Guidance
- Include `browser_specific_settings.safari.prompt` with the original, verbatim user prompt
- Do not modify, paraphrase, or rewrite the prompt - use the exact text the user provided

## Examples

### `manifest.json`

```json
{
  "browser_specific_settings": {
    "safari": {
      "prompt": "Shortcuts for scrolling to the top, bottom, or between main headlines on a page."
    }
  }
}
```
